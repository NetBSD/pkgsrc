# $NetBSD: Makefile,v 1.7 2001/08/27 14:35:15 tron Exp $

DISTNAME=	kdoc-2.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/2.1/distribution/tar/generic/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/2.1/distribution/tar/generic/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/2.1/distribution/tar/generic/src/
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	C++ and IDL Class Documentation Tool

BUILD_DEPENDS+= autoconf>=2.13:../../devel/autoconf

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf

.include "../../mk/bsd.pkg.mk"
