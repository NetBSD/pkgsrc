# $NetBSD: Makefile,v 1.12 1998/07/24 01:56:59 tv Exp $
#

DISTNAME=	pilot-link.0.8.13
PKGNAME=	pilot-link-0.8.13
CATEGORIES=	comms
MASTER_SITES=	ftp://ryeham.ee.ryerson.ca/pub/PalmOS/

MAINTAINER=	sommerfeld@alum.mit.edu

USE_PERL5=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include "../../mk/bsd.pkg.mk"
