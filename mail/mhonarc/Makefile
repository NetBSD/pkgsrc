# $NetBSD: Makefile,v 1.2 1998/08/20 15:17:10 tsarna Exp $
#

DISTNAME=	MHonArc2.2.0
PKGNAME=	mhonarc-2.2.0
CATEGORIES=	mail
MASTER_SITES=	http://www.oac.uci.edu/indiv/ehood/tar/ \
		ftp://hhobel.phl.univie.ac.at/MHonArc/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.oac.uci.edu/indiv/ehood/mhonarc.html

USE_PERL5=	YES

NO_BUILD=
INSTALL_TARGET=	install-batch

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/mhonarc
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mhonarc

.include "../../mk/bsd.pkg.mk"
