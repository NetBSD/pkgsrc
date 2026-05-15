# $NetBSD: Makefile,v 1.1 2026/05/15 07:41:33 wiz Exp $

DISTNAME=	fzssh-1.2.1
CATEGORIES=	net
MASTER_SITES=	# scraper ownload protection, download manually
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fzssh.filezilla-project.org/
COMMENT=	SSH/SFTP library based on libfilezilla
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=		output/meson-private/libfzssh-client.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../devel/meson/build.mk"
.include "../../net/libfilezilla/buildlink3.mk"
.include "../../security/argon2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
