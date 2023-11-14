# $NetBSD: Makefile,v 1.12 2023/11/14 14:01:25 wiz Exp $

DISTNAME=	sndfile-tools-1.5
PKGREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=libsndfile/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libsndfile.github.io/sndfile-tools/
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
