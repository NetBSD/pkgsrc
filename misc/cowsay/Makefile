# $NetBSD: Makefile,v 1.6 2004/04/24 22:46:11 jlam Exp $

DISTNAME=		cowsay-3.03
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.nog.net/pub/tony/cowsay/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.nog.net/~tony/warez/cowsay.shtml
COMMENT=		Configurable talking cow

USE_PERL5=		# defined

SUBST_CLASSES+=		pap
SUBST_STAGE.pap=	pre-install # after patch to avoid sneaking into patches
SUBST_MESSAGE.pap=	Adjusting paths to perl and the cows
SUBST_FILES.pap=	cowsay
SUBST_SED.pap=		-e "s|%BANGPERL%|!${PERL5}|" -e "s|%PREFIX%|${PREFIX}|"

NO_CONFIGURE=		# defined
NO_BUILD=		# defined

INSTALLATION_DIRS=	bin man/man1 share/cows

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cowsay ${PREFIX}/bin
	cd ${PREFIX}/bin; ${LN} -s cowsay cowthink
	${INSTALL_DATA} ${WRKSRC}/cowsay.1 ${PREFIX}/man/man1
	cd ${PREFIX}/man/man1; ${LN} -s cowsay.1 cowthink.1
	${INSTALL_DATA} ${WRKSRC}/cows/*.cow ${PREFIX}/share/cows

.include "../../mk/bsd.pkg.mk"
