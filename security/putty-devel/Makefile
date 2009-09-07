# $NetBSD: Makefile,v 1.2 2009/09/07 18:08:54 ahoka Exp $
#

DISTNAME=	putty-0.60-2009-09-06
PKGNAME=	putty-0.6.20090906
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/ahoka/dist/

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://www.chiark.greenend.org.uk/~sgtatham/putty/
COMMENT=	Free implementation of Telnet and SSH for Win32 and Unix platforms

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
BUILD_DIRS=	unix
BUILD_DEPENDS+=	halibut>=1.0:../../textproc/halibut

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

# Use Unix98 ptys if we have the device, otherwise use the old style.
.if !exists(/dev/ptmx)
CFLAGS+=	-DBSD_PTYS
.endif

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
