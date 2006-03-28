# $NetBSD: Makefile,v 1.16 2006/03/28 20:11:34 joerg Exp $
#

DISTNAME=		aranym-0.8.9beta
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aranym/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://aranym.sourceforge.net/
COMMENT=		Atari Running on Any Machine

USE_TOOLS+=		gmake makedepend
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/${DISTNAME}/src/Unix
USE_TOOLS+=		gzip
MANCOMPRESSED=		yes

BUILD_TARGET=		# void

BUILD_DEFS+=		FIXED_FASTRAM

FIXED_FASTRAM?=		64 # Default value

CONFIGURE_ARGS+=	--enable-fullmmu
CONFIGURE_ARGS+=	--enable-dsp-disasm
CONFIGURE_ARGS+=	--enable-blitsdlblit
CONFIGURE_ARGS+=	--enable-fixedvideoram
CONFIGURE_ARGS+=	--enable-fixedfastram=${FIXED_FASTRAM:Q}
CONFIGURE_ARGS+=	--enable-blitmemmove

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD" && ${OPSYS} != "DragonFly"
CONFIGURE_ARGS+=	--enable-nfpci
.endif

pre-build:
	cd ${WRKSRC} && ${GMAKE} ${MAKE_ARGS} depend

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
