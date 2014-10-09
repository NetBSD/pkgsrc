# $NetBSD: Makefile,v 1.18 2014/10/09 14:06:43 wiz Exp $

DISTNAME=	lsdvd-0.16
PKGREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lsdvd/}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/lsdvd/
COMMENT=	Application displaying the contents of DVDs

GNU_CONFIGURE=		YES
USE_TOOLS+=		autoconf

BUILDLINK_API_DEPENDS.libdvdread+=	libdvdread>=0.9.5nb1

pre-configure:
	cd ${WRKSRC}; autoconf

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
