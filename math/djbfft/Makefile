# $NetBSD: Makefile,v 1.21 2020/06/25 05:42:39 schmonz Exp $

DISTNAME=	djbfft-0.76
CATEGORIES=	math
MASTER_SITES=	http://cr.yp.to/djbfft/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://cr.yp.to/djbfft.html
COMMENT=	Extremely fast library for floating-point convolution
LICENSE=	public-domain

DJB_RESTRICTED=		no
NOT_FOR_PLATFORM=	IRIX-*-*

SUBST_CLASSES+=		djberrno

INSTALLATION_DIRS=	include/djbfft lib

.include "options.mk"

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
