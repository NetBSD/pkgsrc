# $NetBSD: Makefile,v 1.18 2002/08/31 03:47:53 wiz Exp $

DISTNAME=		libmikmod-3.1.10
CATEGORIES=		audio
MASTER_SITES=		http://www.mikmod.org/files/libmikmod/

MAINTAINER=		kuebart@mathematik.uni-ulm.de
HOMEPAGE=		http://www.mikmod.org/
COMMENT=		MikMod Sound Library

USE_GMAKE=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
USE_BUILDLINK2=		# defined

CONFIGURE_ARGS+=	--disable-threads
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

pre-build:
	${RM} -f ${WRKSRC}/docs/mikmod.info*

.include "../../audio/esound/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
