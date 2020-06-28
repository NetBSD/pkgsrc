# $NetBSD: Makefile,v 1.2 2020/06/28 02:33:05 ryoon Exp $

DISTNAME=	open_jtalk-1.11
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=open-jtalk/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://open-jtalk.sourceforge.net/
COMMENT=	Japanese text-to-speech system
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

MAKE_ENV+=	dicdir=${PREFIX}/share/open_jtalk/dic

.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-[0-9].[0-8]*-*)
CFLAGS+=	-fpermissive # for iconv(3) and const char**
.endif

CONFIGURE_ARGS+=	--with-hts-engine-header-path=${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--with-hts-engine-library-path=${BUILDLINK_DIR}/lib
CONFIGURE_ARGS+=	--with-charset=UTF-8

.include "../../audio/hts_engine/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
