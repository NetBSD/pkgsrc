# $NetBSD: Makefile,v 1.10 2002/08/23 01:48:26 grant Exp $
#

DISTNAME=	MHonArc2.5.11
PKGNAME=	mhonarc-2.5.11
CATEGORIES=	mail
MASTER_SITES=	http://www.oac.uci.edu/indiv/ehood/tar/ \
		ftp://hhobel.phl.univie.ac.at/MHonArc/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.oac.uci.edu/indiv/ehood/mhonarc.html
COMMENT=	Mailbox to HTML converter, suitable for list archives

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
