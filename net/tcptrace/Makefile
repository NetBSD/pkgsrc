# $NetBSD: Makefile,v 1.24 2004/08/17 19:19:53 adrianp Exp $
#

DISTNAME=	tcptrace-6.6.1
CATEGORIES=	net
MASTER_SITES=	http://www.tcptrace.org/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.tcptrace.org/
COMMENT=	TCP dump file analysis tool

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

ALL_TARGET=	tcptrace

DOCFILES=	COPYRIGHT FAQ README README.tput_graphs

LDFLAGS.SunOS+=	-lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tcptrace.man ${PREFIX}/man/man1/tcptrace.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcptrace
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/tcptrace
.endfor

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
