# $NetBSD: Makefile,v 1.1 2015/01/17 00:16:12 wiz Exp $

DISTNAME=	speexdsp-1.2rc3
CATEGORIES=	audio
MASTER_SITES=	http://downloads.us.xiph.org/releases/speex/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.speex.org/
COMMENT=	Open-source, patent-free voice codec DSP library
LICENSE=	modified-bsd

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	speexdsp.pc.in
USE_TOOLS+=		pkg-config

BUILDLINK_API_DEPENDS.speex+=	speex>=1.2rc2
.include "../../audio/speex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
