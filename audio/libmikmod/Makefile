# $NetBSD: Makefile,v 1.26 2004/01/22 07:15:00 grant Exp $

DISTNAME=		libmikmod_3.1.10
PKGNAME=		libmikmod-3.1.10
CATEGORIES=		audio
MASTER_SITES=		http://mikmod.raphnet.net/files/

MAINTAINER=		kuebart@mathematik.uni-ulm.de
HOMEPAGE=		http://mikmod.raphnet.net/
COMMENT=		MikMod Sound Library

USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
USE_BUILDLINK2=		# defined
USE_MAKEINFO=		YES
INFO_FILES=		mikmod.info

WRKSRC=			${WRKDIR}/${PKGNAME}
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
