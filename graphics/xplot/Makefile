#	$NetBSD: Makefile,v 1.3 1997/12/14 22:55:11 thorpej Exp $
#
# Packages collection Makefile for: xplot
# Version required: 0.90
# Date created: 10 December 1997
# Whom: thorpej

DISTNAME=	xplot-0.90
CATEGORIES=	x11
MASTER_SITES=	ftp://mercury.lcs.mit.edu/pub/shep/

GNU_CONFIGURE=	yes

DOCFILES=	ANNOUNCE README README.tcp_plots demo.0 demo.1 demo.2 \
		demo.3 demo.4 demo.5 demo.6 demo.7

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xplot
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xplot
.endfor
.endif

.include <bsd.port.mk>
