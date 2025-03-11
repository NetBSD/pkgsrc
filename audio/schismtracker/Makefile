# $NetBSD: Makefile,v 1.16 2025/03/11 09:57:10 nia Exp $

DISTNAME=	schismtracker-20250307.source
PKGNAME=	${DISTNAME:S/.source$//}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=schismtracker/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	fstd.lkml@gmail.com
HOMEPAGE=	https://schismtracker.org/
COMMENT=	Clone of the good old Impulse Tracker
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no
GNU_CONFIGURE=	yes
USE_TOOLS+=	perl pkg-config

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=		gnu99

CONFIGURE_ARGS+=	--enable-flac-linking
CONFIGURE_ARGS+=	--enable-sdl2-linking

PYTHON_FOR_BUILD_ONLY=	tool

.include "options.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../converters/utf8proc/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
