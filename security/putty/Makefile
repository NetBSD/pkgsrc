# $NetBSD: Makefile,v 1.1.1.1 2004/10/29 23:00:30 xtraeme Exp $
#

DISTNAME=	putty-0.56
CATEGORIES=	security
MASTER_SITES=	http://the.earth.li/~sgtatham/putty/latest/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.chiark.greenend.org.uk/~sgtatham/putty/
COMMENT=	Free implementation of Telnet and SSH for Win32 and Unix platforms

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_X11=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/unix

MAKEFILE=	Makefile.gtk

.include "../../mk/bsd.prefs.mk"

.if empty(OPSYS:MLinux)
CFLAGS+=	-DHAVE_NO_SETRESUID
.endif

.if !empty(USE_INET6:M[Yy][Ee][Ss])
CFLAGS+=	-DIPV6
.endif

.if !empty(OPSYS:M*BSD)
CFLAGS+=	-DOMIT_UTMP
.endif

# Unix98 ptys were added some weeks ago in NetBSD -current,
# so use it if we have the device, otherwise use the old style.
.if !exists(/dev/ptmx)
CFLAGS+=	-DBSD_PTYS
.endif

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
