# $NetBSD: Makefile,v 1.5 2022/08/11 05:09:11 gutteridge Exp $

DISTNAME=	nicotine-plus-2.2.2
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nicotine-plus/}
PKGREVISION=	4
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nicotine-plus.github.io/nicotine-plus/
COMMENT=	Graphical client for the Soulseek file sharing network
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-gobject3>=3.18:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-gdbm-[0-9]*:../../databases/py-gdbm

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	setup.py
SUBST_SED.paths+=	-e "s,share/man/man1,${PKGMANDIR}/man1,g"

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/libappindicator/buildlink3.mk"
.include "../../textproc/gspell/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
