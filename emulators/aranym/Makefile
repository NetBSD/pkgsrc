# $NetBSD: Makefile,v 1.1.1.1 2004/07/06 07:28:38 xtraeme Exp $
#

DISTNAME=		aranym-0.8.8beta
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aranym/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://aranym.sourceforge.net/
COMMENT=		Atari Running on Any Machine

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/${DISTNAME}/src/Unix

ALL_TARGET=		# void

CONFIGURE_ARGS+=	--enable-opengl
MANCOMPRESSED=		aranym.1.gz

pre-build:
	cd ${WRKSRC} && ${GMAKE} ${MAKE_ARGS} depend

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
