# $NetBSD: Makefile,v 1.3 2008/01/18 05:06:33 tnn Exp $
#

DISTNAME=	curlftpfs-0.9
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=curlftpfs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://curlftpfs.sourceforge.net/
COMMENT=	FUSE filesystem for acessing FTP hosts

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
