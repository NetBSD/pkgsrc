# $NetBSD: Makefile,v 1.9 2006/08/24 09:58:14 xtraeme Exp $

DISTNAME=	lsdvd-0.16
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=acidrip/}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://untrepid.com/acidrip/lsdvd.html
COMMENT=	Application displaying the contents of DVDs

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_TOOLS+=		autoconf

BUILDLINK_API_DEPENDS.libdvdread+=	libdvdread>=0.9.5nb1

pre-configure:
	cd ${WRKSRC}; autoconf

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
