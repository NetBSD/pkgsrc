# $NetBSD: Makefile,v 1.9 2005/02/21 20:26:09 hubertf Exp $
#

DISTNAME=	synaesthesia-xmms-0.0.3-rc3
PKGNAME=	xmms-synaesthesia-0.0.3rc3
PKGREVISION=	3
CATEGORIES=	audio xmms
MASTER_SITES=	http://staff.xmms.org/zinx/xmms/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://staff.xmms.org/zinx/xmms/
COMMENT=	Port of Synaesthesia to an XMMS plugin

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
USE_X11=	yes

CPPFLAGS+=	-D_POSIX_THREAD_SYSCALL_SOFT=1

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
