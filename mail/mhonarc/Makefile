# $NetBSD: Makefile,v 1.3 2001/01/03 01:49:03 jwise Exp $
#

DISTNAME=	MHonArc2.4.7
PKGNAME=	mhonarc-2.4.7
CATEGORIES=	mail
MASTER_SITES=	http://www.oac.uci.edu/indiv/ehood/tar/ \
		ftp://hhobel.phl.univie.ac.at/MHonArc/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.oac.uci.edu/indiv/ehood/mhonarc.html

USE_PERL5=	YES

NO_BUILD=

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/mhonarc
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mhonarc

do-install:
	( cd ${WRKSRC} && ${PERL5} ./install.me \
		-prefix ${PREFIX} \
		-perl ${LOCALBASE}/bin/perl \
		-libpath ${PREFIX}/lib/mhonarc \
		-docpath ${PREFIX}/share/doc/mhonarc \
		-batch )
		  
.include "../../mk/bsd.pkg.mk"
