# $NetBSD: Makefile,v 1.11 1999/09/15 15:43:11 drochner Exp $
# FreeBSD Id: Makefile,v 1.3 1997/07/19 19:43:36 fenner Exp
#

DISTNAME=	tcptrace.5.2.0
PKGNAME=	tcptrace-5.2.0
CATEGORIES=	net
MASTER_SITES=	http://jarok.cs.ohiou.edu/software/tcptrace/files/5.2.0/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://jarok.cs.ohiou.edu/software/tcptrace/tcptrace.html

WRKSRC=         ${WRKDIR}/tcptrace_5.2.0
GNU_CONFIGURE=	yes

ALL_TARGET=	tcptrace

DOCFILES=	COPYRIGHT README README.tput_graphs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tcptrace.man ${PREFIX}/man/man1/tcptrace.1
	${MKDIR} ${PREFIX}/share/doc/tcptrace
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/tcptrace
.endfor

.include "../../mk/bsd.pkg.mk"
