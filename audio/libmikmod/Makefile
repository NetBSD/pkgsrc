# $NetBSD: Makefile,v 1.9 2001/02/16 13:30:45 wiz Exp $

DISTNAME=		libmikmod-3.1.9
CATEGORIES=		audio
MASTER_SITES=		http://mikmod.darkorb.net/libmikmod/

MAINTAINER=		kuebart@mathematik.uni-ulm.de
HOMEPAGE=		http://mikmod.darkorb.net/
COMMENT=		MikMod Sound Library

DEPENDS+=		esound-0.2.*:../../audio/esound

USE_GMAKE=		# defined
USE_GTEXINFO=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

CONFIGURE_ARGS+=	--disable-threads
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

pre-build:
	${RM} -f ${WRKSRC}/docs/mikmod.info*

.include "../../mk/bsd.pkg.mk"
