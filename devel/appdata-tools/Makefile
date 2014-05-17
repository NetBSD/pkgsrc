# $NetBSD: Makefile,v 1.2 2014/05/17 16:10:42 wiz Exp $

DISTNAME=	appdata_tools_0_1_7
PKGNAME=	${DISTNAME:S/appdata_tools_/appdata-tools-/:S/_/./g}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/hughsie/appdata-tools/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hughsie/appdata-tools/
COMMENT=	Application data tools
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

WRKSRC=	${WRKDIR}/appdata-tools-${DISTNAME}
USE_TOOLS+=	autoconf automake autoreconf gmake intltool intltoolize pkg-config
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && autoreconf -fi && intltoolize --force

.include "../../lang/python/application.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
