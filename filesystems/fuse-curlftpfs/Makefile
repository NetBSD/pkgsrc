# $NetBSD: Makefile,v 1.25 2019/07/01 04:08:08 ryoon Exp $
#

DISTNAME=	curlftpfs-0.9.1
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	18
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=curlftpfs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://curlftpfs.sourceforge.net/
COMMENT=	FUSE filesystem for acessing FTP hosts

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE
CFLAGS.SunOS+=	--std=c99 -D__EXTENSIONS__

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
