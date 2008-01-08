# $NetBSD: Makefile,v 1.17 2008/01/08 17:02:11 adrianp Exp $
#

DISTNAME=	putty-0.60
CATEGORIES=	security
MASTER_SITES=	http://the.earth.li/~sgtatham/putty/0.60/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.chiark.greenend.org.uk/~sgtatham/putty/
COMMENT=	Free implementation of Telnet and SSH for Win32 and Unix platforms

USE_TOOLS+=	gmake
BUILD_DIRS=	${WRKSRC}/unix

MAKE_FILE=	Makefile.gtk
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

PKG_OPTIONS_VAR=	PKG_OPTIONS.putty
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if empty(OPSYS:MLinux)
CFLAGS+=	-DHAVE_NO_SETRESUID
.endif

.if !empty(PKG_OPTIONS:Minet6)
CFLAGS+=	-DIPV6
.endif

.if !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly" || ${OPSYS} == "Darwin"
CFLAGS+=	-DOMIT_UTMP
.endif

# Unix98 ptys were added some weeks ago in NetBSD -current,
# so use it if we have the device, otherwise use the old style.
.if !exists(/dev/ptmx)
CFLAGS+=	-DBSD_PTYS
.endif

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
