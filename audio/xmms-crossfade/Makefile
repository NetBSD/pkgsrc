# $NetBSD: Makefile,v 1.7 2001/10/23 13:14:44 jlam Exp $
#

DISTNAME=		xmms-crossfade-0.2.9
CATEGORIES=		audio
MASTER_SITES=		http://www.netcologne.de/~nc-eisenlpe2/xmms-crossfade/ \
			ftp://ftp.falsehope.com/pub/xmms-crossfade/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netcologne.de/~nc-eisenlpe2/xmms-crossfade/
COMMENT=		Crossfading/Gapless Plugin for XMMS

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
LDFLAGS+=		${LIBOSSAUDIO}
CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

.include "../../mk/x11.buildlink.mk"
.include "../../audio/xmms/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
