# $NetBSD: Makefile,v 1.4 2003/06/10 06:38:47 wiz Exp $
#

DISTNAME=	apg-2.1.0
CATEGORIES=	security
MASTER_SITES=	http://www.adel.nursat.kz/apg/download/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.adel.nursat.kz/apg/
COMMENT=	Tool set for random password generation

MAKE_ENV+=	FLAGS="${CFLAGS}" INSTALL_PREFIX="${PREFIX}"

USE_PERL5=	YES
REPLACE_PERL=	perl/apgcli.pl

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/perl/apgcli.pl ${PREFIX}/bin/apgcli

.include "../../mk/bsd.pkg.mk"
