# $NetBSD: Makefile,v 1.1.1.1 2001/07/11 13:21:07 ad Exp $

DISTNAME=	exim-html-3.20
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.exim.org/pub/exim/ \
		ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/ \
		ftp://ftp.esat.net/pub/networking/mail/mta/exim/

MAINTAINER=	ad@netbsd.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	HTML documentation for the Exim mail transfer agent

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/exim
	${RM} ${WRKDIR}/exim-html-3.20/doc/html/spec
	${CP} -R ${WRKDIR}/exim-html-3.20/doc/html/* ${PREFIX}/share/doc/html/exim

.include "../../mk/bsd.pkg.mk"
