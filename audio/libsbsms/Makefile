# $NetBSD: Makefile,v 1.8 2022/07/25 11:12:19 wiz Exp $

DISTNAME=	libsbsms-2.0.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sbsms/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sbsms.sourceforge.net/
COMMENT=	Subband Sinusoidal Modeling Synthesis
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	sbsms.pc.in
CONFIGURE_ARGS+=	--enable-shared=yes

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "x86_64"
CONFIGURE_ARGS+=	--disable-sse
.endif

.include "../../mk/bsd.pkg.mk"
