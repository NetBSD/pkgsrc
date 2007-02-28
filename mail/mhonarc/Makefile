# $NetBSD: Makefile,v 1.27 2007/02/28 16:04:16 jwise Exp $

DISTNAME=	MHonArc-2.6.16
PKGNAME=	mhonarc-2.6.16
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
		-manpath ${PREFIX}/${PKGMANDIR} \
		-batch

.include "../../mk/bsd.pkg.mk"
