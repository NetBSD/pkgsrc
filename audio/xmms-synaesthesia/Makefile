# $NetBSD: Makefile,v 1.16 2009/05/28 20:49:26 zafer Exp $
#

DISTNAME=	synaesthesia-xmms-0.0.3-rc3
PKGNAME=	xmms-synaesthesia-0.0.3rc3
PKGREVISION=	4
CATEGORIES=	audio xmms
MASTER_SITES=	http://zenthought.org/system/files/asset/2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zinx.xmms.org/xmms/
COMMENT=	Port of Synaesthesia to an XMMS plugin

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CPPFLAGS+=	-D_POSIX_THREAD_SYSCALL_SOFT=1

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
