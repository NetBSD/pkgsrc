# $NetBSD: Makefile,v 1.8 2006/03/15 00:17:43 wiz Exp $

DISTNAME=	koffice-i18n-fr-1.3.5
PKGREVISION=	5
CATEGORIES=	misc kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.3.5/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://www.koffice.org/
COMMENT=	French language pack for KOffice

DEPENDS+=	kdelibs-[0-9]*:../../x11/kdelibs3

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../mk/bsd.pkg.mk"
