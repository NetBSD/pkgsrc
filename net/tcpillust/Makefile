# New ports collection makefile for:	tcpillust
# Date created:		14 April 2000
# Whom:			nishida@csl.sony.co.jp
#
# $FreeBSD: ports/net/tcpillust/Makefile,v 1.1.1.1 2000/07/29 06:26:00 sada Exp $
#

PORTNAME=	tcpillust
PORTVERSION=	1.0a
CATEGORIES=	net tk82 tcl82
MASTER_SITES=	ftp://ftp.csl.sony.co.jp/CSL/nishida/

MAINTAINER=	nishida@csl.sony.co.jp

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82 \
				tcl82.1:${PORTSDIR}/lang/tcl82

USE_IMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=
REQUIRES_MOTIF=	yes

MAN1=	tcpillust.1

DOCS=	README

SAMPLES= tcpclient.log tcpserver.log

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tcpillust
	for i in $(DOCS); do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/tcpillust; \
	done
	${MKDIR} ${PREFIX}/share/doc/tcpillust/sample
	for i in $(SAMPLES); do \
		${INSTALL_DATA} ${WRKSRC}/sample/$$i ${PREFIX}/share/doc/tcpillust/sample; \
	done
.endif

.include <bsd.port.mk>
