# $NetBSD: Makefile,v 1.7 2004/04/13 13:33:27 adam Exp $
#

DISTNAME=	iplog-2.2.3
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ojnk/}

MAINTAINER=	gremlin@portal-to-web.de
HOMEPAGE=	http://ojnk.sourceforge.net/
COMMENT=	Iplog is a tool using pcap to log IP traffic

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES

RCD_SCRIPTS=	iplog

EGDIR=		${PREFIX}/share/examples/iplog

post-patch:
	cd ${WRKSRC}/src && ${SED} s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g \
		< iplog.h > iplog.h.patched && ${MV} iplog.h.patched iplog.h

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/example-iplog.conf ${EGDIR}/iplog.conf

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
