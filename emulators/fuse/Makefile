# $NetBSD: Makefile,v 1.14 2005/06/01 18:02:47 jlam Exp $

DISTNAME=	fuse-0.7.0
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fuse-emulator/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://fuse-emulator.sourceforge.net/
COMMENT=	ZX Spectrum Emulator

USE_PERL5=		build
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk2
LIBS+=	${LIBOSSAUDIO}

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../emulators/libspectrum/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
