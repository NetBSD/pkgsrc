# $NetBSD: Makefile,v 1.15 2012/10/23 17:18:29 asau Exp $
#

DISTNAME=	iplog-2.2.3
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ojnk/}

MAINTAINER=	gremlin@portal-to-web.de
HOMEPAGE=	http://ojnk.sourceforge.net/
COMMENT=	Iplog is a tool using pcap to log IP traffic

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

RCD_SCRIPTS=	iplog

EGDIR=		${PREFIX}/share/examples/iplog

INSTALLATION_DIRS+=	${EGDIR}

post-patch:
	cd ${WRKSRC}/src && ${SED} s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g \
		< iplog.h > iplog.h.patched && ${MV} iplog.h.patched iplog.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/example-iplog.conf ${DESTDIR}${EGDIR}/iplog.conf

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
