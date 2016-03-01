# $NetBSD: Makefile,v 1.2 2016/03/01 20:28:24 jmmv Exp $
#

DISTNAME=	sshfs-2.7
PKGNAME=	fuse-${DISTNAME}
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
