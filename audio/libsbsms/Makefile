# $NetBSD: Makefile,v 1.3 2017/09/16 19:26:42 wiz Exp $

DISTNAME=	libsbsms-2.0.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sbsms/}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
