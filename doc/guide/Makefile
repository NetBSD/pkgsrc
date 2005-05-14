# $NetBSD: Makefile,v 1.11 2005/05/14 22:33:27 rillig Exp $
#

DISTNAME=		htdocs-share-20050507
PKGNAME=		pkgsrc-guide-${PKGVERSION}
CATEGORIES=		# empty
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/Documentation/pkgsrc/
COMMENT=		The pkgsrc guide

# the "install-doc" target installs pkgsrc/doc/pkgsrc.{html,txt} which
# both need to be committed to CVS.

PKGVERSION!=		date '+%Y%m%d'
DIST_SUBDIR=		${PKGBASE}
NO_CONFIGURE=		# defined
NO_MTREE=		# defined
USE_LANGUAGES=		# empty

WRKSRC=			${WRKDIR}/${PKGNAME}

PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
DOCDIR=			${PREFIX}/share/doc/pkgsrc
HTDOCSDIR?=		/usr/cvs/htdocs

BUILD_DEFS+=		OUTPUTS
OUTPUTS?=		lint html html-split ascii pdf

# the html is needed to build the ascii version.
.if !empty(OUTPUTS:Mascii)
OUTPUTS+=		html
.endif

# html output
BUILD_DEPENDS+=		docbook>=4.0:../../textproc/docbook
BUILD_DEPENDS+=		docbook-xml>=4.0:../../textproc/docbook-xml
BUILD_DEPENDS+=		docbook-xsl>=1.62.4:../../textproc/docbook-xsl
BUILD_DEPENDS+=		dsssl-docbook-modular>=1.54:../../textproc/dsssl-docbook-modular
BUILD_DEPENDS+=		opensp>=1.5:../../textproc/opensp
BUILD_DEPENDS+=		libxslt>=1.0.30:../../textproc/libxslt

.if !empty(OUTPUTS:Mhtml*)
BUILD_DEPENDS+=		tidy>=20021108:../../www/tidy
.endif

.if !empty(OUTPUTS:Mascii)
BUILD_DEPENDS+=		w3m>=0.4:../../www/w3m
.endif

.if !empty(OUTPUTS:Mps) || !empty(OUTPUTS:Mpdf)
BUILD_DEPENDS+=		openjade>=1.3.2:../../textproc/openjade
BUILD_DEPENDS+=		tex-jadetex>=3.13:../../print/tex-jadetex
USE_GHOSTSCRIPT=	build
GHOSTSCRIPT_REQD=	7.05
.  include "../../mk/ghostscript.mk"
.endif

pre-extract:
	${MKDIR} ${WRKSRC}
	@cd ${FILESDIR} && ${PAX} -rw . ${WRKSRC}

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
	@${FIND} ${DOCDIR} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"			\
		>> ${PLIST_SRC}
	@${FIND} ${DOCDIR} -type d -print				\
		| ${SORT} -r | ${SED} -e "s,${PREFIX}/,@dirrm ,g"	\
		>> ${PLIST_SRC}

# install the single-file HTML and ascii output into the pkgsrc doc/
# directory, for distribution with pkgsrc.
#
# note that this uses ${CP} and not ${INSTALL_DATA} because this
# shouldn't be done as root.
#
install-doc: build
	${CP} ${WRKSRC}/pkgsrc.html ${_PKGSRCDIR}/doc
	${CP} ${WRKSRC}/pkgsrc.txt ${_PKGSRCDIR}/doc

install-htdocs: build
	${CP} \
		${WRKSRC}/pkgsrc.txt \
		${WRKSRC}/pkgsrc.pdf \
		${WRKSRC}/pkgsrc.ps \
		${WRKSRC}/*.html \
		${HTDOCSDIR}/Documentation/pkgsrc

do-lint:
	cd ${WRKSRC} ; ${MAKE} lint

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
	cd ${FILESDIR};							\
	perl -p -i ".detab.tmp" -e '${DETAB_PROGRAM}' *.xml;		\
	${RM} -f *.xml.detab.tmp

.include "../../mk/bsd.pkg.mk"
