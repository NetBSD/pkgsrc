# $NetBSD: Makefile,v 1.7 2001/09/24 20:03:47 wiz Exp $

DISTNAME=	koffice-2.0.1
PKGNAME=	koffice-1.0.1
CATEGORIES=	misc kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/2.0.1/distribution/tar/generic/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/2.0.1/distribution/tar/generic/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/2.0.1/distribution/tar/generic/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	KDE Office Suite with text processor, spreadsheet, et cetera

DEPENDS+=	kdebase>=2.1:../../x11/kdebase2

.include "../../x11/kde2/Makefile.part2"

LIBS=		-Wl,-export-dynamic

.include "../../mk/bsd.pkg.mk"
