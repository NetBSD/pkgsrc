# $NetBSD: Makefile,v 1.6 2006/02/05 23:10:17 joerg Exp $

DISTNAME=	lsdvd-0.10
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=acidrip/}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://untrepid.com/acidrip/lsdvd.html
COMMENT=	Application displaying the contents of DVDs

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES

BUILDLINK_DEPENDS.libdvdread+=	libdvdread>=0.9.5nb1

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
