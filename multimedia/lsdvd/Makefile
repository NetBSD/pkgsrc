# $NetBSD: Makefile,v 1.2 2004/04/11 03:12:37 minskim Exp $

DISTNAME=	lsdvd-0.10
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=acidrip/}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://acidrip.thirtythreeandathird.net/lsdvd.html
COMMENT=	Application displaying the contents of DVDs

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
