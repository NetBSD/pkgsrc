# $NetBSD: Makefile,v 1.14 2020/05/12 09:33:58 nia Exp $
#

DISTNAME=	trio-1.16
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ctrio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://daniel.haxx.se/projects/trio/
COMMENT=	Fully matured and stable set of printf and string functions
LICENSE=	isc

USE_LIBTOOL=	yes

INSTALLATION_DIRS=	include lib

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
