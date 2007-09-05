# $NetBSD: Makefile,v 1.13 2007/09/05 10:36:43 rillig Exp $

DISTNAME=	exim-html-4.67
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.exim.org/pub/exim/exim4/ \
		ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/exim4/ \
		ftp://ftp.esat.net/pub/networking/mail/mta/exim/exim4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	HTML documentation for the Exim mail transfer agent

NO_BUILD=	yes
INSTALLATION_DIRS=	share/doc/exim/html

do-install:
	cd ${WRKSRC}/doc/html && pax -wr * ${PREFIX}/share/doc/exim/html

.include "../../mk/bsd.pkg.mk"
