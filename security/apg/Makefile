# $NetBSD: Makefile,v 1.17 2014/02/14 04:14:40 rodent Exp $
#

DISTNAME=	apg-2.3.0b
CATEGORIES=	security
MASTER_SITES=	http://www.adel.nursat.kz/apg/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.adel.nursat.kz/apg/
COMMENT=	Tool set for random password generation
LICENSE=	modified-bsd

MAKE_ENV+=	FLAGS=${CFLAGS:M*:Q} INSTALL_PREFIX=${DESTDIR:Q}${PREFIX:Q}

USE_TOOLS+=	perl:run
REPLACE_PERL=	perl/apgcli.pl

OPSYSVARS+=	CS_LIBS
CS_LIBS.Linux+=	-lnsl
CS_LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	CS_LIBS=${CS_LIBS:Q}

INSTALLATION_DIRS+=	bin sbin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

post-extract:
	${CHMOD} -R u+w ${WRKSRC}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/perl/apgcli.pl ${DESTDIR}${PREFIX}/bin/apgcli

.include "../../mk/bsd.pkg.mk"
