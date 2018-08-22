# $NetBSD: Makefile,v 1.2 2018/08/22 09:46:45 wiz Exp $

DISTNAME=	docbook2odf-0.244
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	http://open.comsultia.com/docbook2odf/dwn/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://open.comsultia.com/docbook2odf
COMMENT=	Convert DocBook documentation into ODF documents
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

NO_BUILD=	yes
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PREFIX}/share/applications
INSTALLATION_DIRS+=	${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${PREFIX}/share/${PKGBASE}/examples
INSTALLATION_DIRS+=	${PREFIX}/share/${PKGBASE}/tests
INSTALLATION_DIRS+=	${PREFIX}/share/${PKGBASE}/utils
INSTALLATION_DIRS+=	${PREFIX}/share/${PKGBASE}/xsl

USE_TOOLS+=	pax perl:run

DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-PerlMagick-[0-9]*:../../graphics/p5-PerlMagick
DEPENDS+=	p5-XML-LibXSLT-[0-9]*:../../textproc/p5-XML-LibXSLT

SUBST_CLASSES+=		xsl_path
SUBST_STAGE.xsl_path=	pre-configure
SUBST_FILES.xsl_path=	utils/docbook2odf
SUBST_SED.xsl_path=	-e 's,/usr/share/docbook2odf/xsl,${PREFIX}/share/${PKGBASE}/xsl,g'

REPLACE_PERL+=  utils/docbook2odf utils/maketests

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/utils/docbook2odf ${DESTDIR}${PREFIX}/bin/docbook2odf
	${INSTALL_SCRIPT} ${WRKSRC}/utils/maketests ${DESTDIR}${PREFIX}/share/${PKGBASE}/utils/maketests
	${INSTALL_MAN} ${WRKSRC}/docs/docbook2odf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/docbook2odf.1
	${INSTALL_DATA} ${WRKSRC}/bindings/desktop/docbook2odf.desktop ${DESTDIR}${PREFIX}/share/applications/docbook2odf.desktop
	${INSTALL_DATA} ${WRKSRC}/license ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/license
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/README
	cd ${WRKSRC}/examples; ${PAX} -rw . ${DESTDIR}${PREFIX}/share/${PKGBASE}/examples
	cd ${WRKSRC}/tests; ${PAX} -rw . ${DESTDIR}${PREFIX}/share/${PKGBASE}/tests
	cd ${WRKSRC}/xsl; ${PAX} -rw . ${DESTDIR}${PREFIX}/share/${PKGBASE}/xsl

.include "../../mk/bsd.pkg.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
