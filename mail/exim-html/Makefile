# $NetBSD: Makefile,v 1.5.4.1 2004/05/30 09:03:54 grant Exp $

DISTNAME=	exim-html-4.30
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.exim.org/pub/exim/exim4/ \
		ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/exim4/ \
		ftp://ftp.esat.net/pub/networking/mail/mta/exim/exim4/
EXTRACT_SUFX=  	.tar.bz2

MAINTAINER=	ad@NetBSD.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	HTML documentation for the Exim mail transfer agent

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/exim
	${CP} -R ${WRKDIR}/${DISTNAME}/doc/html/* ${PREFIX}/share/doc/html/exim

.include "../../mk/bsd.pkg.mk"
