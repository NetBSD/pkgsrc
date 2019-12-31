# $NetBSD: Makefile,v 1.27 2019/12/31 12:10:20 schmonz Exp $
#

DISTNAME=	rioutil-${GITHUB_TAG}
PKGNAME=	${DISTNAME:S/-v/-/}
GITHUB_TAG=	v1.5.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=hjelmn/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/hjelmn/rioutil/
COMMENT=	Program and library to interface with Rio 600, 800, Nike psa[play
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		autoreconf autoconf automake aclocal pkg-config
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} && autoreconf -ivf

ONLY_FOR_PLATFORM=	Darwin-*-* Linux-*-* NetBSD-1.6.*-* NetBSD-[2-9].*-*
# depends on -r1.6 of sys/dev/usb/urio.c
ONLY_FOR_PLATFORM+=	NetBSD-1.5Z-* NetBSD-1.5Z[A-Z]-*
ONLY_FOR_PLATFORM+=	DragonFly-*-* FreeBSD-*-* OpenBSD-*-*

.include "../../audio/id3lib/buildlink3.mk"
.include "../../mk/libusb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
