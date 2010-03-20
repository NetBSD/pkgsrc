# $NetBSD: Makefile,v 1.17 2010/03/20 01:32:56 schmonz Exp $

DISTNAME=	djbfft-0.76
CATEGORIES=	math
MASTER_SITES=	http://cr.yp.to/djbfft/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cr.yp.to/djbfft.html
COMMENT=	Extremely fast library for floating-point convolution
LICENSE=	public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

DJB_RESTRICTED=		no
NOT_FOR_PLATFORM=	IRIX-*-*

INSTALLATION_DIRS=	include/djbfft lib

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
