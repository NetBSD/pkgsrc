# $NetBSD: Makefile,v 1.8 2005/07/16 01:19:18 jlam Exp $
#

DISTNAME=	apg-2.2.3
CATEGORIES=	security
MASTER_SITES=	http://www.adel.nursat.kz/apg/download/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.adel.nursat.kz/apg/
COMMENT=	Tool set for random password generation

MAKE_ENV+=	FLAGS="${CFLAGS}" INSTALL_PREFIX="${PREFIX}"

USE_TOOLS+=	perl:run
REPLACE_PERL=	perl/apgcli.pl

OPSYSVARS+=	CS_LIBS
CS_LIBS.Linux+=	-lnsl
CS_LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	CS_LIBS="${CS_LIBS}"

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/perl/apgcli.pl ${PREFIX}/bin/apgcli

.include "../../mk/bsd.pkg.mk"
