# $NetBSD: Makefile,v 1.2 2000/07/31 20:24:15 itojun Exp $
# $FreeBSD: ports/net/tcpillust/Makefile,v 1.1.1.1 2000/07/29 06:26:00 sada Exp $
#

DISTNAME=	tcpillust-1.0a
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.csl.sony.co.jp/CSL/nishida/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.csl.sony.co.jp/person/nishida/tcpillust.html

DEPENDS+=	tk-*:../../x11/tk80
DEPENDS+=	tcl-*:../../lang/tcl80

USE_IMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl-include=${LOCALBASE}/include/tcl8.0 \
		--with-tk-include=${LOCALBASE}/include/tk8.0 \
		--with-tcl-lib=${LOCALBASE}/lib \
		--with-tk-lib=${LOCALBASE}/lib

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

.include "../../mk/bsd.pkg.mk"
