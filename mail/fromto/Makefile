# $NetBSD: Makefile,v 1.4 2001/09/09 20:36:33 agc Exp $
#

DISTNAME=	fromto-1.5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=	#empty

MAINTAINER=	bad@netbsd.org
COMMENT=	Sendmail logfile viewer

RESTRICTED=	"Redistribution allowed for non-commercial purposes only"

USE_PERL5=	yes
WRKSRC=		${WRKDIR}

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/fromto.in

do-build:
	(cd ${WRKSRC} ; ${SED} -e "1s,/usr/local,${PREFIX}," fromto.in >fromto)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fromto ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
