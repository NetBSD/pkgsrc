# $NetBSD: Makefile,v 1.19 2003/10/03 16:15:13 kristerw Exp $
# FreeBSD Id: Makefile,v 1.3 1997/07/19 19:43:36 fenner Exp
#

DISTNAME=	tcptrace-6.4.2
CATEGORIES=	net
MASTER_SITES=	http://www.tcptrace.org/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.tcptrace.org/
COMMENT=	TCP dump file analysis tool

GNU_CONFIGURE=	yes
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub
USE_BUILDLINK2=	yes

ALL_TARGET=	tcptrace

DOCFILES=	COPYRIGHT FAQ README README.tput_graphs

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lnsl -lsocket -lm
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tcptrace.man ${PREFIX}/man/man1/tcptrace.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcptrace
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/tcptrace
.endfor

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
