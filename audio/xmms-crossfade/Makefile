# $NetBSD: Makefile,v 1.4 2001/08/16 05:13:04 zuntum Exp $
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
USE_X11=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
LDFLAGS+=		-lossaudio
CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

.include "../../audio/xmms/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
