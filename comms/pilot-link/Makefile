# $NetBSD: Makefile,v 1.11 1998/07/17 20:59:41 tv Exp $
#

DISTNAME=	pilot-link.0.8.13
PKGNAME=	pilot-link-0.8.13
CATEGORIES=	comms
MASTER_SITES=	ftp://ryeham.ee.ryerson.ca/pub/PalmOS/

MAINTAINER=	sommerfeld@alum.mit.edu

BUILD_DEPENDS=	${PREFIX}/bin/libtool:../../devel/libtool

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBTOOL=${PREFIX}/bin/libtool \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include "../../mk/bsd.pkg.mk"
