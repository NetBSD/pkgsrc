# $NetBSD: Makefile,v 1.17 2003/07/17 22:51:55 grant Exp $
# FreeBSD Id: Makefile,v 1.3 1997/07/19 19:43:36 fenner Exp
#

DISTNAME=	tcptrace.5.2.1
PKGNAME=	tcptrace-5.2.1
WRKSRC=         ${WRKDIR}/tcptrace_5.2.1
CATEGORIES=	net
MASTER_SITES=	http://jarok.cs.ohiou.edu/software/tcptrace/files/5.2.1/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://jarok.cs.ohiou.edu/software/tcptrace/tcptrace.html
COMMENT=	TCP dump file analysis tool

GNU_CONFIGURE=	yes

ALL_TARGET=	tcptrace

DOCFILES=	COPYRIGHT README README.tput_graphs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tcptrace.man ${PREFIX}/man/man1/tcptrace.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcptrace
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/tcptrace
.endfor

.include "../../mk/bsd.pkg.mk"
