# $NetBSD: Makefile,v 1.4 2020/08/18 17:57:39 leot Exp $

DISTNAME=	sndfile-tools-1.04
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/libsndfile/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mega-nerd.com/libsndfile/tools/
COMMENT=	Small collection of programs that use libsndfile
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

# Avoid conflicting with libsamplerate
post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/sndfile-resample
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/sndfile-resample.1

.include "options.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
