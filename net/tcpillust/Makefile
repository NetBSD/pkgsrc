# $NetBSD: Makefile,v 1.7 2001/05/05 19:51:18 jlam Exp $
# $FreeBSD: ports/net/tcpillust/Makefile,v 1.1.1.1 2000/07/29 06:26:00 sada Exp $
#

DISTNAME=	tcpillust-1.0a
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.csl.sony.co.jp/CSL/nishida/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.csl.sony.co.jp/person/nishida/tcpillust.html
COMMENT=	Graphical TCP connection analysis tool

DEPENDS+=	tk>=8.3.2:../../x11/tk

USE_IMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl-include=${LOCALBASE}/include \
		--with-tk-include=${LOCALBASE}/include \
		--with-tcl-lib=${LOCALBASE}/lib \
		--with-tk-lib=${LOCALBASE}/lib

DOCS=	README

SAMPLES= tcpclient.log tcpserver.log

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcpillust
	for i in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/tcpillust; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcpillust/sample
	for i in ${SAMPLES}; do \
		${INSTALL_DATA} ${WRKSRC}/sample/$$i ${PREFIX}/share/doc/tcpillust/sample; \
	done

.include "../../mk/bsd.pkg.mk"
