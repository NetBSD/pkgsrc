# $NetBSD: Makefile,v 1.2 2015/12/27 07:33:07 dholland Exp $

DISTNAME=	libsbsms-2.0.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sbsms/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://sbsms.sourceforge.net/
COMMENT=	Subband Sinusoidal Modeling Synthesis
LICENSE=	gnu-gpl-v2

# configure script demands -msse; should be taught to use altivec and
# whatever else on other platforms. Except where nonexistent.
BROKEN_EXCEPT_FOR_PLATFORM=	*-*-i386 *-*-x86_64
NOT_FOR_PLATFORM=		*-*-m68k

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	sbsms.pc.in
CONFIGURE_ARGS+=	--enable-shared=yes

.include "../../mk/bsd.pkg.mk"
