# $NetBSD: Makefile,v 1.5 2021/12/08 16:04:21 adam Exp $
#

DISTNAME=	sshfs-3.7.2
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=libfuse/}
GITHUB_PROJECT=	sshfs
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libfuse/sshfs/
COMMENT=	File system client based on the SFTP protocol
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c
USE_TOOLS=	pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
