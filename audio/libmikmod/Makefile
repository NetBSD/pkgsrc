# $NetBSD: Makefile,v 1.21 2003/08/09 10:29:55 seb Exp $

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
USE_MAKEINFO=		YES
INFO_FILES=		mikmod.info

CONFIGURE_ARGS+=	--disable-threads
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

pre-build:
	${RM} -f ${WRKSRC}/docs/mikmod.info*

.include "../../mk/bsd.prefs.mk"

.if defined(USE_OSS)
.  include "../../mk/ossaudio.buildlink2.mk"
.endif

.include "../../audio/esound/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
