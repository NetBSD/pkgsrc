# $NetBSD: Makefile,v 1.2 2016/09/19 13:04:27 wiedi Exp $
#

DISTNAME=	bunny-0.93
PKGREVISION=	1
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

LDFLAGS.SunOS+=	-lsocket -lnsl

do-install:
.for program in bunny-exec bunny-flow bunny-gcc bunny-main bunny-trace
	${INSTALL_PROGRAM} ${WRKSRC}/${program} ${DESTDIR}${PREFIX}/bin/${program}
.endfor

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
