# $NetBSD: Makefile,v 1.11 2001/06/26 16:30:56 jlam Exp $

DISTNAME=		libmikmod-3.1.9
CATEGORIES=		audio
MASTER_SITES=		http://mikmod.darkorb.net/libmikmod/

MAINTAINER=		kuebart@mathematik.uni-ulm.de
HOMEPAGE=		http://mikmod.darkorb.net/
COMMENT=		MikMod Sound Library

USE_GMAKE=		# defined
USE_GTEXINFO=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

USE_BUILDLINK_ONLY=	# defined
USE_CONFIG_WRAPPER=	# defined
REPLACE_BUILDLINK=	libmikmod-config

CONFIGURE_ARGS+=	--disable-threads
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

pre-build:
	${RM} -f ${WRKSRC}/docs/mikmod.info*

.include "../../audio/esound/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
