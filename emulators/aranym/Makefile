# $NetBSD: Makefile,v 1.5 2004/10/03 00:14:40 tv Exp $
#

DISTNAME=		aranym-0.8.9beta
PKGREVISION=	1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aranym/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://aranym.sourceforge.net/
COMMENT=		Atari Running on Any Machine

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_X11=		yes
GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/${DISTNAME}/src/Unix

ALL_TARGET=		# void

BUILD_DEFS+=		FIXED_FASTRAM

FIXED_FASTRAM?=		64 # Default value

CONFIGURE_ARGS+=	--enable-fullmmu
CONFIGURE_ARGS+=	--enable-dsp-disasm
CONFIGURE_ARGS+=	--enable-blitsdlblit
CONFIGURE_ARGS+=	--enable-fixedvideoram
CONFIGURE_ARGS+=	--enable-fixedfastram=${FIXED_FASTRAM}
CONFIGURE_ARGS+=	--enable-blitmemmove

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
CONFIGURE_ARGS+=	--enable-nfpci
.endif

MANCOMPRESSED=		aranym.1.gz

pre-build:
	cd ${WRKSRC} && ${GMAKE} ${MAKE_ARGS} depend

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
