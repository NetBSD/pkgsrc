# $NetBSD: Makefile,v 1.4 2001/04/07 04:32:40 tron Exp $

DISTNAME=	koffice-2.0.1
PKGNAME=	koffice-1.0.1
CATEGORIES=	misc kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/2.0.1/distribution/tar/generic/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/2.0.1/distribution/tar/generic/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/2.0.1/distribution/tar/generic/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://www.kde.org/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.koffice.org/
COMMENT=	KDE Office Suite with text processor, spreadsheet, ...

DEPENDS+=	kdebase-2.1:../../x11/kdebase2

.include "../../x11/kde2/Makefile.part2"

CONFIGURE_ENV+=	LIBS="-Wl,-export-dynamic"

.include "../../mk/bsd.pkg.mk"
