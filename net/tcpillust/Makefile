# $NetBSD: Makefile,v 1.15 2006/02/05 23:10:31 joerg Exp $

DISTNAME=	tcpillust-1.0a
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.csl.sony.co.jp/CSL/nishida/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.csl.sony.co.jp/person/nishida/tcpillust.html
COMMENT=	Graphical TCP connection analysis tool

USE_IMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--with-tcl-include=${BUILDLINK_PREFIX.tcl}/include
CONFIGURE_ARGS+=--with-tcl-lib=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=--with-tk-include=${BUILDLINK_PREFIX.tk}/include
CONFIGURE_ARGS+=--with-tk-lib=${BUILDLINK_PREFIX.tk}/lib

DOCS=		README
SAMPLES=	tcpclient.log tcpserver.log

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcpillust
	for i in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/tcpillust; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcpillust/sample
	for i in ${SAMPLES}; do \
		${INSTALL_DATA} ${WRKSRC}/sample/$$i ${PREFIX}/share/doc/tcpillust/sample; \
	done

.include "../../lang/tcl83/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
