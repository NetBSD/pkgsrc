# $NetBSD: Makefile,v 1.2 2003/01/17 23:15:24 hubertf Exp $
#

DISTNAME=	p0f-1.8.2
CATEGORIES=	security net
MASTER_SITES=	http://www.stearns.org/p0f/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dawszy@arhea.net
COMMENT=	passive OS fingerprinting tool

pre-build:
	${SED} \
		-e 's,@PREFIX@,${LOCALBASE},'\
		<${WRKSRC}/p0f.c > ${WRKSRC}/p0f.c.tmp
	${MV}	${WRKSRC}/p0f.c.tmp ${WRKSRC}/p0f.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/p0f ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/p0f.fp ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/p0f.README
	${INSTALL_DATA} ${WRKSRC}/p0frep ${PREFIX}/share/doc/p0frep

.include "../../mk/bsd.pkg.mk"
