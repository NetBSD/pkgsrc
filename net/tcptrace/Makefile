# New ports collection makefile for:	tcptrace
# Version required:	4.1.3
# Date created:		3 March 1997
# Whom:			fenner
#
# $NetBSD: Makefile,v 1.4 1998/01/24 21:47:07 hubertf Exp $
# FreeBSD Id: Makefile,v 1.3 1997/07/19 19:43:36 fenner Exp
#

DISTNAME=	tcptrace
PKGNAME=	tcptrace-4.1.3
CATEGORIES=	net
MASTER_SITES=	http://jarok.cs.ohiou.edu/software/tcptrace/files/4.1.3/

MAINTAINER=	fenner@FreeBSD.ORG

GNU_CONFIGURE=	yes

ALL_TARGET=	tcptrace

DOCFILES=	COPYRIGHT README README.tput_graphs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tcptrace
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/tcptrace
.endfor
.endif

.include <bsd.port.mk>
