# $NetBSD: Makefile,v 1.27 2004/02/11 08:36:17 xtraeme Exp $

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
USE_BUILDLINK3=		# defined
USE_MAKEINFO=		YES
INFO_FILES=		mikmod.info

WRKSRC=			${WRKDIR}/${PKGNAME}
CONFIGURE_ARGS+=	--disable-threads
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		USE_ESOUND
.if defined(USE_ESOUND) && !empty(USE_ESOUND:M[Yy][Ee][Ss])
.include "../../audio/esound/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

pre-build:
	${RM} -f ${WRKSRC}/docs/mikmod.info*

.if defined(USE_OSS)
.  include "../../mk/ossaudio.buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
