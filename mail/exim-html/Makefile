# $NetBSD: Makefile,v 1.17 2008/05/25 21:42:21 joerg Exp $

DISTNAME=	exim-html-4.69
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.exim.org/pub/exim/exim4/ \
		ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/exim4/ \
		ftp://ftp.esat.net/pub/networking/mail/mta/exim/exim4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	HTML documentation for the Exim mail transfer agent

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes
INSTALLATION_DIRS=	share/doc/exim/html

USE_TOOLS+=	pax

do-install:
	cd ${WRKSRC}/doc/html && pax -wr * \
		${DESTDIR}${PREFIX}/share/doc/exim/html

.include "../../mk/bsd.pkg.mk"
