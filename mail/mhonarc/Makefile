# $NetBSD: Makefile,v 1.1 1998/06/05 20:06:39 tv Exp $
#

DISTNAME=	MHonArc2.2.0
PKGNAME=	mhonarc-2.2.0
CATEGORIES=	mail
MASTER_SITES=	http://www.oac.uci.edu/indiv/ehood/tar/ \
		ftp://hhobel.phl.univie.ac.at/MHonArc/

MAINTAINER=	tv@netbsd.org

USE_PERL5=	YES

NO_BUILD=
INSTALL_TARGET=	install-batch

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/mhonarc
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mhonarc

.include "../../mk/bsd.pkg.mk"
