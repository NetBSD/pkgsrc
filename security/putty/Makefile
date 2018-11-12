# $NetBSD: Makefile,v 1.54 2018/11/12 03:52:51 ryoon Exp $
#

DISTNAME=	putty-0.69
PKGREVISION=	5
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

.if empty(OPSYS:MLinux)
CFLAGS+=	-DHAVE_NO_SETRESUID
.endif

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

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
