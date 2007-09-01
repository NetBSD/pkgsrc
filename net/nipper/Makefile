# $NetBSD: Makefile,v 1.1.1.1 2007/09/01 22:33:53 adrianp Exp $
#

DISTNAME=	nipper-0.10.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nipper/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://nipper.sourceforge.net/
COMMENT=	Performs security audits of network device configuration

INSTALLATION_DIRS=	${PREFIX}/share/doc/nipper

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} -o nipper nipper.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nipper ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${PREFIX}/share/doc/nipper

.include "../../mk/bsd.pkg.mk"
