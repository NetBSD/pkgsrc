# $NetBSD: Makefile,v 1.1.1.1 2003/02/14 23:56:39 hubertf Exp $
#

DISTNAME=	synaesthesia-xmms-0.0.3-rc3
PKGNAME=	xmms-synaesthesia-0.0.3rc3
CATEGORIES=	audio xmms
MASTER_SITES=	http://staff.xmms.org/zinx/xmms/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://staff.xmms.org/zinx/xmms/
COMMENT=	Port of Synaesthesia to an XMMS plugin

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_X11=	yes
LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig
CPPFLAGS+=	-D_POSIX_THREAD_SYSCALL_SOFT=1

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
