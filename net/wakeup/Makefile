# $NetBSD: Makefile,v 1.1.1.1 1999/11/18 22:28:15 hubertf Exp $
#

DISTNAME=	hpwake.c.gz
PKGNAME=	wakeup-1.0
CATEGORIES=	sysutils net
MASTER_SITES=	http://141.99.132.33/wol/
EXTRACT_SUFX=	# empty

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.berens-partner.de/wann/computer/wol.html

NO_WRKSUBDIR=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/${DISTNAME}
	${GUNZIP_CMD} ${WRKSRC}/${DISTNAME}

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -O2 -o ${DISTNAME:C/.c.gz//} ${DISTNAME:C/.gz//} )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME:C/.c.gz//} ${PREFIX}/bin/${PKGNAME:C/-.*$//}

.include "../../mk/bsd.pkg.mk"
