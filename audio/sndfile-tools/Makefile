# $NetBSD: Makefile,v 1.1 2020/05/09 09:55:32 nia Exp $

DISTNAME=	sndfile-tools-1.04
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/libsndfile/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mega-nerd.com/libsndfile/tools/
COMMENT=	Small collection of programs that use libsndfile
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "options.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
