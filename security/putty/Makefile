# $NetBSD: Makefile,v 1.20 2010/03/19 13:28:09 joerg Exp $
#

DISTNAME=	putty-0.60
PKGNAME=	putty-0.60nb1
CATEGORIES=	security
MASTER_SITES=	http://the.earth.li/~sgtatham/putty/0.60/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.chiark.greenend.org.uk/~sgtatham/putty/
COMMENT=	Free implementation of Telnet and SSH for Win32 and Unix platforms

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake pkg-config
BUILD_DIRS=	unix

MAKE_FILE=	Makefile.gtk
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

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
