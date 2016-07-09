# $NetBSD: Makefile,v 1.40 2016/07/09 13:03:34 wiz Exp $

DISTNAME=	luma-3.0.7
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=luma/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://luma.sourceforge.net/
COMMENT=	LDAP browser
LICENSE=	gnu-gpl-v2

REPLACE_PYTHON=		luma/luma.py
INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PYSITELIB}/luma/plugins/browser

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-qt3-base, py-ldap

SUBST_CLASSES+=		luma
SUBST_STAGE.luma=	pre-configure
SUBST_FILES.luma=	luma/luma.py
SUBST_SED.luma=		-e "s|@PATH@|${PREFIX}/${PYSITELIB}/luma|"
SUBST_MESSAGE.luma=	Adding library path to luma.

post-extract:
	for f in ${WRKSRC}/luma/luma.py ${WRKSRC}/setup.py; do	\
		${TR} -d '\r' < $${f} > $${f}.new;		\
		${MV} $${f}.new $${f};				\
	done

# world-writeable files
pre-build:
	${CHMOD} 0644 ${WRKSRC}/data/icons/*/*.png
	${CHMOD} 0644 ${WRKSRC}/data/icons/*/*.svg
	${CHMOD} 0644 ${WRKSRC}/data/*.desktop

# some templates are not installed, do it manually
# https://sourceforge.net/p/luma/bugs/48/
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/luma.1.gz ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${CP} -R ${WRKSRC}/luma/plugins/browser/templates ${DESTDIR}${PREFIX}/${PYSITELIB}/luma/plugins/browser/templates

.include "../../databases/py-ldap/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
