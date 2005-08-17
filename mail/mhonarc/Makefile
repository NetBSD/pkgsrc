# $NetBSD: Makefile,v 1.24 2005/08/17 03:29:27 jwise Exp $

DISTNAME=	MHonArc-2.6.15
PKGNAME=	mhonarc-2.6.15
CATEGORIES=	mail
MASTER_SITES=	http://www.mhonarc.org/release/MHonArc/tar/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.mhonarc.org/
COMMENT=	Mailbox to HTML converter, suitable for list archives

USE_TOOLS+=	perl:run
NO_BUILD=	YES

INSTALLATION_DIRS=	bin lib man share/doc

do-install:
	cd ${WRKSRC} && ${PERL5} ./install.me \
		-prefix ${PREFIX} \
		-perl ${PERL5} \
		-binpath ${PREFIX}/bin \
		-libpath ${PREFIX}/lib/mhonarc \
		-docpath ${PREFIX}/share/doc/mhonarc \
		-manpath ${PREFIX}/man \
		-batch

.include "../../mk/bsd.pkg.mk"
