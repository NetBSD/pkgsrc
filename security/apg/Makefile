# $NetBSD: Makefile,v 1.5 2003/07/17 22:52:51 grant Exp $
#

DISTNAME=	apg-2.1.0
CATEGORIES=	security
MASTER_SITES=	http://www.adel.nursat.kz/apg/download/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.adel.nursat.kz/apg/
COMMENT=	Tool set for random password generation

MAKE_ENV+=	FLAGS="${CFLAGS}" INSTALL_PREFIX="${PREFIX}"

USE_PERL5=	YES
REPLACE_PERL=	perl/apgcli.pl

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/perl/apgcli.pl ${PREFIX}/bin/apgcli

.include "../../mk/bsd.pkg.mk"
