# $NetBSD: Makefile,v 1.71 2022/08/11 05:09:13 gutteridge Exp $
#

DISTNAME=	putty-0.76
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://the.earth.li/~sgtatham/putty/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.chiark.greenend.org.uk/~sgtatham/putty/
COMMENT=	Free implementation of Telnet and SSH for Win32 and Unix platforms
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config
BUILD_DIRS=	unix

MAKE_FILE=	Makefile.gtk
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "options.mk"

.if !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly" || ${OPSYS} == "Darwin"
CFLAGS+=	-DOMIT_UTMP
.endif

# Unix98 ptys were added some time ago in NetBSD -current,
# so use it if we have the device, otherwise use the old style.
.if !exists(/dev/ptmx)
CFLAGS+=	-DBSD_PTYS
.endif

LDFLAGS.SunOS+=	-lsocket -lnsl
CFLAGS.SunOS+=	-DBSD_COMP
CFLAGS.Darwin+=	-DHAVE_FUTIMES -DHAVE_NO_SETRESUID
CFLAGS.NetBSD+=	-DHAVE_FUTIMES -DHAVE_NO_SETRESUID
CFLAGS.Linux+=	-DHAVE_FUTIMES -DHAVE_NO_SETRESUID
LDFLAGS.Linux+=	-ldl

.include "../../x11/gtk3/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.gtk3:Mquartz)
# Override default GTK_CONFIG from Makefile.gtk to prevent search for x11.pc
MAKE_FLAGS+=	"GTK_CONFIG=pkg-config gtk+-3.0"
CFLAGS+=	-DOSX_GTK
.endif
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
