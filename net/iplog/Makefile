# $NetBSD: Makefile,v 1.1.1.1 2003/04/06 11:06:04 hubertf Exp $
#

DISTNAME=	iplog-2.2.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ojnk/}

MAINTAINER=	gremlin@portal-to-web.de
HOMEPAGE=	http://ojnl.sourceforge.net
COMMENT=	Iplog is a tool using pcap to log ip traffic

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

CFLAGSTMP="-I${PREFIX}/include -Wall"
LDFLAGSTMP="-L${PREFIX}/lib -Wl,-R${PREFIX}/lib"
LIBSTMP="-lpthread"

USE_GMAKE= YES

post-patch:
	cd ${WRKSRC}/src && ${SED} s,%PREFIX%/etc,${PKG_SYSCONFBASE},g < iplog.h > iplog.h.patched && ${MV} iplog.h.patched iplog.h

do-configure:
	cd ${WRKSRC} && CFLAGS=${CFLAGSTMP} \
	LDFLAGS=${LDFLAGSTMP} \
	LIBS=${LIBSTMP} \
	MAKE=${GMAKE} \
	${SH} ./configure --prefix=${PREFIX} --prefix=${GNU_CONFIGURE_PREFIX}

do-build:
	cd ${WRKSRC} && ${GMAKE} all

post-build:
	${SED} \
	-e 's|%PREFIX%|${PREFIX}|' \
	<${FILESDIR}/iplog >${WRKDIR}/iplog

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/iplog ${PREFIX}/etc/rc.d/iplog
	${INSTALL_DATA} ${WRKSRC}/example-iplog.conf ${PREFIX}/etc/iplog.conf.sample

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
