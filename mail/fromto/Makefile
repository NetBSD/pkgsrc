# $NetBSD: Makefile,v 1.22 2019/08/11 13:21:28 wiz Exp $

DISTNAME=	fromto-1.5
PKGREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=	#empty

MAINTAINER=	bad@NetBSD.org
COMMENT=	Sendmail logfile viewer
LICENSE=	fromto-license

RESTRICTED=	Redistribution allowed for non-commercial purposes only
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}
USE_TOOLS+=	perl:run

INSTALLATION_DIRS=	bin

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/fromto.in

do-build:
	(cd ${WRKSRC} ; ${SED} -e "1s,/usr/local,${PREFIX}," fromto.in >fromto)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fromto ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
