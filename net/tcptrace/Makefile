#	$NetBSD: Makefile,v 1.3 1997/12/14 23:44:58 thorpej Exp $
#
# New ports collection makefile for:	tcptrace
# Version required:	4.1.3
# Date created:		3 March 1997
# Whom:			fenner
#
# Id: Makefile,v 1.3 1997/07/19 19:43:36 fenner Exp
#

DISTNAME=	tcptrace-4.1.3
CATEGORIES=	net
MASTER_SITES=	http://jarok.cs.ohiou.edu/software/tcptrace/files/4.1.3/
DISTFILES=	tcptrace.tar.gz

GNU_CONFIGURE=	yes

MAINTAINER=	fenner@FreeBSD.ORG

WRKSRC=		${WRKDIR}/tcptrace
ALL_TARGET=	tcptrace

DOCFILES=	COPYRIGHT README README.tput_graphs

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tcptrace
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/tcptrace
.endfor
.endif

.include <bsd.port.mk>
