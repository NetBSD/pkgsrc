# $NetBSD: Makefile,v 1.4 2007/08/08 17:12:44 xtraeme Exp $
#

DISTNAME=	vbetool_0.7-1
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.srcf.ucam.org/~mjg59/vbetool/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.srcf.ucam.org/~mjg59/vbetool/
COMMENT=	Run real-mode video BIOS code to alter hardware state

ONLY_FOR_PLATFORM+=	Linux-*-i386 NetBSD-*-i386 NetBSD-*-x86_64

WRKSRC=		${WRKDIR}/vbetool-0.7
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x86emu

.include "../../mk/bsd.prefs.mk"

# This gives us libi386 and libx86_64.
LIBS.NetBSD+=	-l${MACHINE_ARCH}

.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
