# $NetBSD: Makefile,v 1.2 2000/12/05 19:30:58 drochner Exp $

DISTNAME=		cowsay-3.03
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.nog.net/pub/tony/cowsay/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.nog.net/~tony/warez/cowsay.shtml

USE_PERL5=		# defined

NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:
	cd ${WRKSRC}; ${SH} install.sh ${PREFIX}

.include "../../mk/bsd.pkg.mk"
