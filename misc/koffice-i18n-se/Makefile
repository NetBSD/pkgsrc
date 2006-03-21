# $NetBSD: Makefile,v 1.11 2006/03/21 19:24:46 wiz Exp $

DISTNAME=	koffice-i18n-se-1.3.5
PKGREVISION=	5
CATEGORIES=	misc kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.3.5/src/
EXTRACT_SUFX=	.tar.bz2

BUILD_DEPENDS+=	kdelibs>=3:../../x11/kdelibs3

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://www.koffice.org/
COMMENT=	Northern Sami language pack for KOffice

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

USE_PKGLOCALEDIR=	YES

.include "../../mk/bsd.pkg.mk"
