# $NetBSD: Makefile,v 1.10 2012/10/23 19:51:28 asau Exp $
#

DISTNAME=	vbetool_0.7-1
PKGNAME=	vbetool-0.7.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.codon.org.uk/~mjg59/vbetool/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.codon.org.uk/~mjg59/vbetool/
COMMENT=	Run real-mode video BIOS code to alter hardware state

ONLY_FOR_PLATFORM+=	Linux-*-i386 NetBSD-*-i386 NetBSD-*-x86_64

CONFLICTS+=	vbetool-0.7-[0-9]*

WRKSRC=		${WRKDIR}/vbetool-0.7
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x86emu

.include "../../mk/bsd.prefs.mk"

# This gives us libi386 and libx86_64.
LIBS.NetBSD+=	-l${MACHINE_ARCH}

.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
