# $NetBSD: Makefile,v 1.1.1.1 2007/08/08 12:00:34 xtraeme Exp $
#

DISTNAME=	vbetool_0.7-1
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	sysutils
MASTER_SITES=	http://www.srcf.ucam.org/~mjg59/vbetool/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.srcf.ucam.org/~mjg59/vbetool/
COMMENT=	Run real-mode video BIOS code to alter hardware state

ONLY_FOR_PLATFORM+=	Linux-*-i386 NetBSD-*-i386

WRKSRC=		${WRKDIR}/vbetool-0.7
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x86emu

LIBS.NetBSD+=	-li386

.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
