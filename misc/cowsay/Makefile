# $NetBSD: Makefile,v 1.4 2003/07/17 21:48:50 grant Exp $

DISTNAME=		cowsay-3.03
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.nog.net/pub/tony/cowsay/

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://www.nog.net/~tony/warez/cowsay.shtml
COMMENT=		Configurable talking cow

USE_PERL5=		# defined

NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:
	cd ${WRKSRC}; ${SH} install.sh ${PREFIX}

.include "../../mk/bsd.pkg.mk"
