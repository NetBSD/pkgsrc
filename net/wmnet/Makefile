# $NetBSD: Makefile,v 1.24 2022/06/03 18:41:44 wiz Exp $

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

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} > 099944
BROKEN=		"Needs to be converted to SIOCGIFDATA ioctl instead of kmem."
.endif

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "MirBSD"
MAKE_FLAGS+=	INSTPGMFLAGS=""
SPECIAL_PERMS+=	bin/wmnet ${BINOWN} kmem 2555
.endif

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
