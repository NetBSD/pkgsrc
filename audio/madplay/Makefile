# $NetBSD: Makefile,v 1.25 2004/11/22 22:58:42 wiz Exp $
#

DISTNAME=	madplay-0.15.2b
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mad/} \
		ftp://ftp.mars.org/pub/mpeg/

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mad/
COMMENT=	High-quality MPEG audio decoder

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

BUILD_DEFS+=	USE_ESOUND
BUILD_DEFS+=	USE_OSS

.include "../../mk/bsd.prefs.mk"

.if empty(USE_ESOUND:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=        --without-esd
.endif

.if !empty(USE_ESOUND:M[Yy][Ee][Ss])
.include "../../audio/esound/buildlink3.mk"
.endif
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.if defined(USE_OSS)
.  include "../../mk/ossaudio.buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
