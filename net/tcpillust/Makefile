# $NetBSD: Makefile,v 1.20 2010/02/11 22:59:24 joerg Exp $

DISTNAME=	tcpillust-1.0a
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.sonycsl.co.jp/CSL/nishida/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sonycsl.co.jp/person/nishida/tcpillust.html
COMMENT=	Graphical TCP connection analysis tool

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--with-tcl-include=${BUILDLINK_PREFIX.tcl}/include
CONFIGURE_ARGS+=--with-tcl-lib=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=--with-tk-include=${BUILDLINK_PREFIX.tk}/include
CONFIGURE_ARGS+=--with-tk-lib=${BUILDLINK_PREFIX.tk}/lib

DOCS=		README
SAMPLES=	tcpclient.log tcpserver.log

INSTALLATION_DIRS+=	share/doc/tcpillust/sample

post-install:
	for i in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/share/doc/tcpillust; \
	done
	for i in ${SAMPLES}; do \
		${INSTALL_DATA} ${WRKSRC}/sample/$$i ${DESTDIR}${PREFIX}/share/doc/tcpillust/sample; \
	done

.include "../../lang/tcl/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
