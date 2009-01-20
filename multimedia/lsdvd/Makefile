# $NetBSD: Makefile,v 1.14 2009/01/20 00:34:35 snj Exp $

DISTNAME=	lsdvd-0.16
PKGREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lsdvd/}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://untrepid.com/acidrip/lsdvd.html
COMMENT=	Application displaying the contents of DVDs

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		autoconf

BUILDLINK_API_DEPENDS.libdvdread+=	libdvdread>=0.9.5nb1

pre-configure:
	cd ${WRKSRC}; autoconf

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
