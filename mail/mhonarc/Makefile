# $NetBSD: Makefile,v 1.18 2004/06/21 20:13:32 adrianp Exp $
#

DISTNAME=	MHonArc-2.6.10
PKGNAME=	mhonarc-2.6.10
CATEGORIES=	mail
MASTER_SITES=	http://www.oac.uci.edu/indiv/ehood/tar/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.mhonarc.org/
COMMENT=	Mailbox to HTML converter, suitable for list archives

USE_PERL5=	YES

NO_BUILD=	YES

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
