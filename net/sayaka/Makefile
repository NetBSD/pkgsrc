# $NetBSD: Makefile,v 1.10 2017/05/29 12:20:24 wiz Exp $

DISTNAME=	sayaka-3.3.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=isaki68k/}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION_NOREV}//}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/isaki68k/sayaka
COMMENT=	Terminal specific Twitter client
LICENSE=	modified-bsd AND apache-2.0

USE_TOOLS+=	gmake pax pkg-config

INSTALLATION_DIRS+=	bin share/sayaka

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vala/sayaka ${DESTDIR}${PREFIX}/bin

BUILDLINK_DEPMETHOD.vala= build
BUILDLINK_API_DEPENDS.vala+=    vala>=0.28.0
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
