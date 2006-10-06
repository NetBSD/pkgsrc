# $NetBSD: Makefile,v 1.1.1.1 2006/10/06 21:10:41 rillig Exp $
#

DISTNAME=		portability-book-${TODAY}
CATEGORIES=		# empty
MASTER_SITES=		${MASTER_SITE_LOCAL}
DISTFILES=		htdocs-share-20061001.tar.gz

MAINTAINER=		rillig@NetBSD.org
#HOMEPAGE=		http://www.NetBSD.org/Documentation/pkgsrc/
COMMENT=		The pkgsrc portability book

TODAY!=			date '+%Y%m%d'
DIST_SUBDIR=		pkgsrc-guide
NO_MTREE=		yes
USE_LANGUAGES=		# none

PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
DOCDIR=			${PREFIX}/share/doc/pkgsrc-portability
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

DEPENDS+=		netbsd-doc-print>=1.2:../../meta-pkgs/netbsd-doc-print

# The source files are only symlinked into the WRKSRC, so that they can
# be easily modified, should the "lint" phase fail.
pre-extract:
	${MKDIR} ${WRKSRC}
	${LN} -s ${FILESDIR}/* ${WRKSRC}
	ln -s ${PKGSRCDIR}/doc/guide/files/share ${WRKSRC}/

do-build:
.for _output_ in ${OUTPUTS}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} ${_output_}
.endfor

post-build:
	@${RM} -f ${WRKSRC}/portability.tmp.html

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
.if !empty(OUTPUTS:Mhtml) || !empty(OUTPUTS:Mhtml-split)
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/htdocs/NetBSD.css ${DOCDIR}
.endif
.if !empty(OUTPUTS:Mascii)
	${INSTALL_DATA} ${WRKSRC}/portability.txt ${DOCDIR}
.endif
.if !empty(OUTPUTS:Mpdf)
	${INSTALL_DATA} ${WRKSRC}/portability.ps ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/portability.pdf ${DOCDIR}
.endif

post-install:
	${FIND} ${DOCDIR} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"			\
		>> ${PLIST_SRC}
	${FIND} ${DOCDIR} -type d -print				\
		| ${SORT} -r | ${SED} -e "s,${PREFIX}/,@dirrm ,g"	\
		>> ${PLIST_SRC}

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
