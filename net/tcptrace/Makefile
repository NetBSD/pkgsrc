# $NetBSD: Makefile,v 1.7 1998/06/03 13:16:57 agc Exp $
# FreeBSD Id: Makefile,v 1.3 1997/07/19 19:43:36 fenner Exp
#

DISTNAME=	tcptrace
PKGNAME=	tcptrace-4.1.3
CATEGORIES=	net
MASTER_SITES=	http://jarok.cs.ohiou.edu/software/tcptrace/files/4.1.3/

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	yes

ALL_TARGET=	tcptrace

DOCFILES=	COPYRIGHT README README.tput_graphs

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tcptrace
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/tcptrace
.endfor
.endif

.include "../../mk/bsd.pkg.mk"
