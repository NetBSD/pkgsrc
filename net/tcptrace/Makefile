# $NetBSD: Makefile,v 1.22 2004/07/25 00:21:16 grant Exp $
# FreeBSD Id: Makefile,v 1.3 1997/07/19 19:43:36 fenner Exp
#

DISTNAME=	tcptrace-6.4.2
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
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/tcptrace
.endfor

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
