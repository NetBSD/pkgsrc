# $NetBSD: Makefile,v 1.3 2020/03/08 16:49:31 wiz Exp $
#

DISTNAME=	sshfs-2.7
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=libfuse/}
GITHUB_PROJECT=	sshfs
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libfuse/sshfs/
COMMENT=	File system client based on the SFTP protocol
LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	Darwin-*-* Linux-*-*

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS=	pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
