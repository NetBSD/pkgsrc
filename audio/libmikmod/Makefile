# $NetBSD: Makefile,v 1.22 2003/09/14 18:00:30 jmmv Exp $

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

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		USE_ESOUND
.if defined(USE_ESOUND) && !empty(USE_ESOUND:M[Yy][Ee][Ss])
.include "../../audio/esound/buildlink2.mk"
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

pre-build:
	${RM} -f ${WRKSRC}/docs/mikmod.info*

.if defined(USE_OSS)
.  include "../../mk/ossaudio.buildlink2.mk"
.endif

.include "../../mk/bsd.pkg.mk"
