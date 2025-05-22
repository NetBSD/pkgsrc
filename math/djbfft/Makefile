# $NetBSD: Makefile,v 1.23 2025/05/22 04:51:29 schmonz Exp $

DISTNAME=	djbfft-0.76
CATEGORIES=	math
MASTER_SITES=	http://cr.yp.to/djbfft/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://cr.yp.to/djbfft.html
COMMENT=	Extremely fast library for floating-point convolution
LICENSE=	public-domain

NOT_FOR_PLATFORM=	IRIX-*-*

FORCE_C_STD=		c99

DJB_ERRNO_FIXUP=	error.h

INSTALLATION_DIRS=	include/djbfft lib

.include "options.mk"

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
