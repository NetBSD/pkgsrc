# $NetBSD: Makefile,v 1.3 2002/12/09 11:40:48 ad Exp $

DISTNAME=	exim-html-4.10
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.exim.org/pub/exim/exim4/ \
		ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/exim4/ \
		ftp://ftp.esat.net/pub/networking/mail/mta/exim/exim4/
EXTRACT_SUFX=  	.tar.bz2

MAINTAINER=	ad@netbsd.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	HTML documentation for the Exim mail transfer agent

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/exim
	${CP} -R ${WRKDIR}/${DISTNAME}/doc/html/* ${PREFIX}/share/doc/html/exim

.include "../../mk/bsd.pkg.mk"
