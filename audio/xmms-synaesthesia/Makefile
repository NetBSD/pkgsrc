# $NetBSD: Makefile,v 1.6 2003/07/17 21:24:18 grant Exp $
#

DISTNAME=	synaesthesia-xmms-0.0.3-rc3
PKGNAME=	xmms-synaesthesia-0.0.3rc3
PKGREVISION=	2
CATEGORIES=	audio xmms
MASTER_SITES=	http://staff.xmms.org/zinx/xmms/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://staff.xmms.org/zinx/xmms/
COMMENT=	Port of Synaesthesia to an XMMS plugin

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_LIBTOOL=	yes
USE_X11=	yes
LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig
CPPFLAGS+=	-D_POSIX_THREAD_SYSCALL_SOFT=1

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
