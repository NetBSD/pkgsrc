# $NetBSD: Makefile,v 1.14 2001/10/22 03:48:12 mycroft Exp $

DISTNAME=		libmikmod-3.1.9
CATEGORIES=		audio
MASTER_SITES=		http://www.mikmod.org/files/libmikmod/

MAINTAINER=		kuebart@mathematik.uni-ulm.de
HOMEPAGE=		http://www.mikmod.org/
COMMENT=		MikMod Sound Library

USE_GMAKE=		# defined
USE_GTEXINFO=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
USE_BUILDLINK_ONLY=	# defined

CONFIGURE_ARGS+=	--disable-threads
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

pre-build:
	${RM} -f ${WRKSRC}/docs/mikmod.info*

.include "../../audio/esound/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
