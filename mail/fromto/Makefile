# $NetBSD: Makefile,v 1.7 2004/01/20 12:19:43 agc Exp $
#

DISTNAME=	fromto-1.5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=	#empty

MAINTAINER=	bad@NetBSD.org
COMMENT=	Sendmail logfile viewer

RESTRICTED=	"Redistribution allowed for non-commercial purposes only"

WRKSRC=		${WRKDIR}
USE_PERL5=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/fromto.in

do-build:
	(cd ${WRKSRC} ; ${SED} -e "1s,/usr/local,${PREFIX}," fromto.in >fromto)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fromto ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
