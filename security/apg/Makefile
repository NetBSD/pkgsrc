# $NetBSD: Makefile,v 1.1.1.1 2001/03/05 23:21:03 hubertf Exp $
#

DISTNAME=	apg-1.2.12
CATEGORIES=	security
MASTER_SITES=	http://www.adel.nursat.kz/apg/download/

MAINTAINER=	zuntum@eik.pl
HOMEPAGE=	http://www.adel.nursat.kz/apg/
COMMENT=	Tool set for random password generation

MAKE_ENV+=	"CC=${CC}"						\
		"FLAGS=${CFLAGS}"					\
		"INSTALL_PREFIX=${PREFIX}"

post-patch:
	${SED} "s|/usr/bin/perl|${LOCALBASE}/bin/perl|g"		\
		${WRKSRC}/perl/apgcli.pl > ${WRKDIR}/apgcli.pl

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/apgcli.pl ${PREFIX}/bin/apgcli

.include "../../mk/bsd.pkg.mk"
