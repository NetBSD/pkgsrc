# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 18:39:37 jlam Exp $
#

DISTNAME=		xmms-mad-0.0.9
CATEGORIES=		audio
MASTER_SITES=		http://www.superduper.net/downloads/xmms-mad/

MAINTAINER=		jmcneill@netbsd.org
HOMEPAGE=		http://www.superduper.net/xmms-mad/
COMMENT=		Input plugin for XMMS that uses libmad

DEPENDS+=		mad>=0.14:../../audio/mad

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LDFLAGS="-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib"
CONFIGURE_ENV+=		CFLAGS="-I${LOCALBASE}/include"
CPPFLAGS+=              -D_POSIX_THREAD_SYSCALL_SOFT=1

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == NetBSD)
CPPFLAGS+=              -DHAVE_NANOSLEEP=1
.endif

.include "../../audio/xmms/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
