# $NetBSD: Makefile,v 1.3 2004/10/03 00:13:03 tv Exp $

DISTNAME=	lsdvd-0.10
PKGREVISION=	1
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
