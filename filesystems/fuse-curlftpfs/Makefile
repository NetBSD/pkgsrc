# $NetBSD: Makefile,v 1.45 2024/05/29 16:32:28 adam Exp $
#

DISTNAME=	curlftpfs-0.9.2
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=curlftpfs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://curlftpfs.sourceforge.net/
COMMENT=	FUSE filesystem for acessing FTP hosts
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE
CFLAGS.SunOS+=	--std=c99 -D__EXTENSIONS__

CONFIGURE_ENV+=	ac_cv_func_working_mktime=yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
