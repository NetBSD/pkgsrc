# $NetBSD: Makefile,v 1.3 2026/06/16 17:06:59 nia Exp $

DISTNAME=	fzssh-1.3.0
CATEGORIES=	net
MASTER_SITES=	# scraper ownload protection, download manually
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fzssh.filezilla-project.org/
COMMENT=	SSH/SFTP library based on libfilezilla
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

USE_CXX_FEATURES+=	c++20

PKGCONFIG_OVERRIDE+=		output/meson-private/libfzssh-client.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../devel/meson/build.mk"
.include "../../net/libfilezilla/buildlink3.mk"
.include "../../security/argon2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
