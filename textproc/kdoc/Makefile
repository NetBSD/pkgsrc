# $NetBSD: Makefile,v 1.2 2000/12/20 08:54:17 skrll Exp $
#

DISTNAME=	kdoc-2.0.1b
WRKSRC=		${WRKDIR}/kdoc-2.0.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/2.0.1/distribution/tar/generic/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/2.0.1/distribution/tar/generic/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/2.0.1/distribution/tar/generic/src/
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www.kde.org/

BUILD_DEPENDS+= autoconf:../../devel/autoconf

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../mk/bsd.pkg.mk"
