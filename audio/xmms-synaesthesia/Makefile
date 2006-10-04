# $NetBSD: Makefile,v 1.14 2006/10/04 20:44:20 wiz Exp $
#

DISTNAME=	synaesthesia-xmms-0.0.3-rc3
PKGNAME=	xmms-synaesthesia-0.0.3rc3
PKGREVISION=	4
CATEGORIES=	audio xmms
MASTER_SITES=	http://zinx.xmms.org/xmms/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zinx.xmms.org/xmms/
COMMENT=	Port of Synaesthesia to an XMMS plugin

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CPPFLAGS+=	-D_POSIX_THREAD_SYSCALL_SOFT=1

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
