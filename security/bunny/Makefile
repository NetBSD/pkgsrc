# $NetBSD: Makefile,v 1.1.1.1 2016/07/09 21:43:24 rillig Exp $
#

DISTNAME=	bunny-0.93
CATEGORIES=	security
MASTER_SITES=	http://bunny-the-fuzzer.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/bunny-the-fuzzer/
COMMENT=	Tools with C code security fuzzer
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/bunny
USE_TOOLS+=	gmake
AUTO_MKDIRS=	yes

do-install:
.for program in bunny-exec bunny-flow bunny-gcc bunny-main bunny-trace
	${INSTALL_PROGRAM} ${WRKSRC}/${program} ${DESTDIR}${PREFIX}/bin/${program}
.endfor

.include "../../mk/bsd.pkg.mk"
