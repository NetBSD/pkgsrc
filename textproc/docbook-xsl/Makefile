# $NetBSD: Makefile,v 1.20 2004/06/06 04:29:17 schmonz Exp $
#

DISTNAME=	docbook-xsl-1.65.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docbook/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://docbook.sourceforge.net/
COMMENT=	Docbook XSL modular stylesheet

DEPENDS=	docbook-xml>=4.2:../../textproc/docbook-xml

USE_BUILDLINK3=	YES
USE_LANGUAGES=	# empty
NO_BUILD=	YES
NO_CONFIGURE=	YES

DOCDIR=		${PREFIX}/share/doc/docbook-xsl
EGDIR=		${PREFIX}/share/examples/docbook-xsl
XSLDIR=		${PREFIX}/share/xsl/docbook
XSLMODS=	common extensions fo html htmlhelp images javahelp \
		lib manpages params profiling tools xhtml

XML_CATALOGS=	${XSLDIR}/catalog

FIX_APOS=	doc/html/htmlhelp.hhp.windows\'.html
FIX_APOS+=	doc/html/htmlhelp.show.toolbar.text\'.html

SUBST_CLASSES+=		fix-apos
SUBST_STAGE.fix-apos=	post-patch
SUBST_MESSAGE.fix-apos=	"Fixing references to files with apostrophes in names."
SUBST_FILES.fix-apos=	${FIX_APOS:H:u:S/$/\/*/}
SUBST_SED.fix-apos=
.for f in ${FIX_APOS}
SUBST_SED.fix-apos+=	-e "s|${f:T}|${f:T:S/\'/.apos/g}|g"
.endfor

post-extract:
.for f in ${FIX_APOS}
	${MV} ${WRKSRC}/${f} ${WRKSRC}/${f:S/\'/.apos/g}
.endfor
.undef f

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/doc && ${PAX} -rw -pp -pm . ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/template && ${PAX} -rw -pp -pm . ${EGDIR}
	${INSTALL_DATA_DIR} ${XSLDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION ${XSLDIR}
	@for d in ${XSLMODS}; do \
	    ${ECHO} "${INSTALL_DATA_DIR} ${XSLDIR}/$$d"; \
	    ${ECHO} "cd ${WRKSRC} && ${PAX} -rw -pp -pm $$d ${XSLDIR}/"; \
	    cd ${WRKSRC} && ${PAX} -rw -pp -pm $$d ${XSLDIR}/; \
	done
	${INSTALL_DATA} ${FILESDIR}/catalog ${XSLDIR}/catalog

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
