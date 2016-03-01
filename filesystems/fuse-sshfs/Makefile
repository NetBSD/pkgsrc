# $NetBSD: Makefile,v 1.1 2016/03/01 11:30:07 jmmv Exp $
#

DISTNAME=	sshfs-2.6
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=libfuse/}
GITHUB_PROJECT=	sshfs
GITHUB_RELEASE=	${DISTNAME:C/[-.]/_/g}

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
