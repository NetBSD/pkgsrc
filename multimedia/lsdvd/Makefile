# $NetBSD: Makefile,v 1.11 2007/02/26 17:55:14 snj Exp $

DISTNAME=	lsdvd-0.16
PKGREVISION=	2
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
