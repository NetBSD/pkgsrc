# $NetBSD: Makefile,v 1.2 2001/06/11 06:34:19 jlam Exp $
#

DISTNAME=		xmms-crossfade-0.2.7
CATEGORIES=		audio
MASTER_SITES=		http://www.netcologne.de/~nc-eisenlpe2/xmms-crossfade/ \
			ftp://ftp.falsehope.com/pub/xmms-crossfade/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netcologne.de/~nc-eisenlpe2/xmms-crossfade/
COMMENT=		Crossfading/Gapless Plugin for XMMS

DEPENDS+=		xmms>=1.2.4:../../audio/xmms

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
LDFLAGS+=		-lossaudio
CPPFLAGS+=		-I${LOCALBASE}/include
CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

.include "../../mk/bsd.pkg.mk"
