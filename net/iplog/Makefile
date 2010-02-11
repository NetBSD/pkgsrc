# $NetBSD: Makefile,v 1.14 2010/02/11 21:36:18 joerg Exp $
#

DISTNAME=	iplog-2.2.3
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ojnk/}

MAINTAINER=	gremlin@portal-to-web.de
HOMEPAGE=	http://ojnk.sourceforge.net/
COMMENT=	Iplog is a tool using pcap to log IP traffic

PKG_DESTDIR_SUPPORT=	user-destdir

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
