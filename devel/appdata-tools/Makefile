# $NetBSD: Makefile,v 1.27 2020/06/02 08:23:33 adam Exp $

DISTNAME=	appdata_tools-0.1.7
PKGREVISION=	21
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=hughsie/}
GITHUB_PROJECT=	appdata-tools
# -0.1.7 into _0_1_7
GITHUB_TAG=	${DISTNAME:S/./_/g:S/-/_/g}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://github.com/hughsie/appdata-tools/
COMMENT=	Application data tools
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

WRKSRC=		${WRKDIR}/appdata-tools-${GITHUB_TAG}
USE_TOOLS+=	autoconf automake autoreconf gmake intltool intltoolize
USE_TOOLS+=	pkg-config xgettext
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && autoreconf -fi && intltoolize --force

.include "../../lang/python/application.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
