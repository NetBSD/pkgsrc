# $NetBSD: Makefile,v 1.1.1.1 1999/03/12 17:40:14 bad Exp $
#

DISTNAME=	fromto-1.5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=	#empty

MAINTAINER=	bad@netbsd.org

USE_PERL5=	yes
NO_WRKSUBDIR=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/fromto.in

do-build:
	(cd ${WRKSRC} ; ${SED} -e "1s,/usr/local,${PREFIX}," fromto.in >fromto)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fromto ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
