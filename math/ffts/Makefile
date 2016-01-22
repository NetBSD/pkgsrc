# $NetBSD: Makefile,v 1.1 2016/01/22 14:57:41 gson Exp $

GIT_COMMIT=		fa1780c68593762b1e4bdbc46d83912db3eba27a

DISTNAME=		${GIT_COMMIT}
PKGNAME=		ffts-20140106
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=anthonix/}/ffts/archive/

MAINTAINER=		gson@NetBSD.org
HOMEPAGE=		https://github.com/anthonix/ffts
COMMENT=		The Fastest Fourier Transform in the South
LICENSE=		modified-bsd

WRKSRC=			${WRKDIR}/ffts-${GIT_COMMIT}

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-sse --enable-single

.include "../../mk/bsd.pkg.mk"
