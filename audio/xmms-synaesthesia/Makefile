# $NetBSD: Makefile,v 1.15 2008/07/14 12:55:59 joerg Exp $
#

DISTNAME=	synaesthesia-xmms-0.0.3-rc3
PKGNAME=	xmms-synaesthesia-0.0.3rc3
PKGREVISION=	4
CATEGORIES=	audio xmms
MASTER_SITES=	http://zinx.xmms.org/xmms/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zinx.xmms.org/xmms/
COMMENT=	Port of Synaesthesia to an XMMS plugin

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CPPFLAGS+=	-D_POSIX_THREAD_SYSCALL_SOFT=1

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
