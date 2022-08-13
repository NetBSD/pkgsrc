# $NetBSD: Makefile,v 1.3 2022/08/13 13:24:19 gson Exp $

GIT_COMMIT=		fe86885ecafd0d16eb122f3212403d1d5a86e24e

DISTNAME=		${GIT_COMMIT}
PKGNAME=		ffts-20170617
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=anthonix/}/ffts/archive/

MAINTAINER=		gson@NetBSD.org
HOMEPAGE=		https://github.com/anthonix/ffts
COMMENT=		The Fastest Fourier Transform in the South
LICENSE=		modified-bsd

WRKSRC=			${WRKDIR}/ffts-${GIT_COMMIT}

USE_TOOLS+=		gmake autoconf automake autoheader aclocal
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-sse --enable-single

ONLY_FOR_PLATFORM=	*-*-x86_64

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../mk/bsd.pkg.mk"
