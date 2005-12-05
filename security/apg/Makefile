# $NetBSD: Makefile,v 1.9 2005/12/05 20:50:54 rillig Exp $
#

DISTNAME=	apg-2.2.3
CATEGORIES=	security
MASTER_SITES=	http://www.adel.nursat.kz/apg/download/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.adel.nursat.kz/apg/
COMMENT=	Tool set for random password generation

MAKE_ENV+=	FLAGS=${CFLAGS:M*:Q} INSTALL_PREFIX=${PREFIX:Q}

USE_TOOLS+=	perl:run
REPLACE_PERL=	perl/apgcli.pl

OPSYSVARS+=	CS_LIBS
CS_LIBS.Linux+=	-lnsl
CS_LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	CS_LIBS=${CS_LIBS:Q}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/perl/apgcli.pl ${PREFIX}/bin/apgcli

.include "../../mk/bsd.pkg.mk"
