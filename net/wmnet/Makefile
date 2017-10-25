# $NetBSD: Makefile,v 1.23 2017/10/25 21:51:02 khorben Exp $

DISTNAME=	wmnet-1.06
PKGREVISION=	5
CATEGORIES=	net x11
#MASTER_SITES=	http://www.katharineosborne.com/wmnet/

# Random patches:
# http://www.rampant.org/~dp/software/wmnet.solaris.patch -- included
# http://glitchy.net/code/wmnet/wmnet-1.06-ul_fix.diff
# http://mail.afterstep.org/pipermail/as-users/2004-December/001457.html

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.katharineosborne.com/wmnet/
COMMENT=	Dockable network monitor

USE_IMAKE=	YES

MAKE_FLAGS+=	CCOPTIONS=${CFLAGS:Q}
MAKE_FLAGS+=	LOCAL_LDFLAGS=${LDFLAGS:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "MirBSD"
MAKE_FLAGS+=	INSTPGMFLAGS=""
SPECIAL_PERMS+=	bin/wmnet ${BINOWN} kmem 2555
.endif

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
