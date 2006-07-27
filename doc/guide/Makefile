# $NetBSD: Makefile,v 1.23 2006/07/27 07:06:13 rillig Exp $
#

DISTNAME=		pkgsrc-guide-${PKGVERSION}
CATEGORIES=		# empty
MASTER_SITES=		${MASTER_SITE_LOCAL}
DISTFILES=		htdocs-share-20060529.tar.gz

MAINTAINER=		packages@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/Documentation/pkgsrc/
COMMENT=		The pkgsrc guide

# the "install-doc" target installs pkgsrc/doc/pkgsrc.{html,txt} which
# both need to be committed to CVS.

PKGVERSION!=		date '+%Y%m%d'
DIST_SUBDIR=		${PKGBASE}
NO_MTREE=		yes
USE_LANGUAGES=		# empty

PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
DOCDIR=			${PREFIX}/share/doc/pkgsrc
.if exists(/usr/cvs/htdocs)
HTDOCSDIR?=		/usr/cvs/htdocs
.endif
HTDOCSDIR?=		${.CURDIR}/../../../htdocs

BUILD_DEFS+=		OUTPUTS
OUTPUTS?=		lint html html-split ascii pdf

.if defined(OUTPUTS)
.  if !empty(OUTPUTS:Mascii)
# the html is needed to build the ascii version.
OUTPUTS+=		html
.  endif

# only override the Makefile.common default if it is explicitly set
_GUIDE_OUTPUTS=		${OUTPUTS}
.endif

.include "Makefile.common"

# The source files are only symlinked into the WRKSRC, so that they can
# be easily modified, should the "lint" phase fail.
pre-extract:
	${MKDIR} ${WRKSRC}
	${LN} -s ${FILESDIR}/* ${WRKSRC}

do-build:
.for _output_ in ${OUTPUTS}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} ${_output_}
.endfor

post-build:
	@${RM} -f ${WRKSRC}/pkgsrc.tmp.html

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
.if !empty(OUTPUTS:Mhtml) || !empty(OUTPUTS:Mhtml-split)
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/htdocs/NetBSD.css ${DOCDIR}
.endif
.if !empty(OUTPUTS:Mascii)
	${INSTALL_DATA} ${WRKSRC}/pkgsrc.txt ${DOCDIR}
.endif
.if !empty(OUTPUTS:Mpdf)
	${INSTALL_DATA} ${WRKSRC}/pkgsrc.ps ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/pkgsrc.pdf ${DOCDIR}
.endif

post-install:
	${FIND} ${DOCDIR} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"			\
		>> ${PLIST_SRC}
	${FIND} ${DOCDIR} -type d -print				\
		| ${SORT} -r | ${SED} -e "s,${PREFIX}/,@dirrm ,g"	\
		>> ${PLIST_SRC}

# install the single-file HTML and ascii output into the pkgsrc doc/
# directory, for distribution with pkgsrc.
#
# note that this uses ${CP} and not ${INSTALL_DATA} because the files
# stay in the development directories and have nothing to do with
# the permissions or ownership of installed files.
#
install-doc: build
	${CP} ${WRKSRC}/pkgsrc.html ${PKGSRCDIR}/doc
	${CP} ${WRKSRC}/pkgsrc.txt ${PKGSRCDIR}/doc

install-htdocs: build
	cd ${WRKSRC} && ${CP} pkgsrc.txt pkgsrc.pdf pkgsrc.ps *.html	\
		${HTDOCSDIR}/Documentation/pkgsrc

.PHONY: regenerate regenerate-doc regenerate-htdocs
regenerate: regenerate-doc regenerate-htdocs

regenerate-doc: build
	@${STEP_MSG} "Updating the files in pkgsrc/doc"
	cd .. && cvs update pkgsrc.*
	${MAKE} ${MAKEFLAGS} install-doc
	@${STEP_MSG} "Committing the files in pkgsrc/doc"
	cd .. && cvs commit -m "re-generated." pkgsrc.*

regenerate-htdocs: build
	@${STEP_MSG} "Updating the files in htdocs"
	cd ${HTDOCSDIR}/Documentation/pkgsrc && cvs update
	${MAKE} ${MAKEFLAGS} install-htdocs
	@${STEP_MSG} "Committing the files in htdocs"
	cd ${HTDOCSDIR}/Documentation/pkgsrc && cvs commit -m "re-generated."

do-lint:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} lint

DETAB_PROGRAM= \
	if (/<programlisting>/ .. /<\/programlisting>/) {		\
		while (/(.*?)\t(.*)/s) {				\
			my $$filler = " " x (8 - (length($$1) % 8));	\
			$$_ = "$$1$$filler$$2";				\
		}							\
	}

# remove tabulators from the <programlisting> tags.
# TeX does not like them.
.PHONY: detab
detab:
	cd ${FILESDIR} &&						\
	perl -p -i".detab.tmp" -e '${DETAB_PROGRAM}' *.xml &&		\
	${RM} -f *.xml.detab.tmp

.include "../../mk/bsd.pkg.mk"
