# $NetBSD: Makefile,v 1.4 2003/09/19 23:08:28 dent Exp $
#

DISTNAME=	iplog-2.2.3
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ojnk/}

MAINTAINER=	gremlin@portal-to-web.de
HOMEPAGE=	http://ojnk.sourceforge.net/
COMMENT=	Iplog is a tool using pcap to log ip traffic

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES

CFLAGSTMP="-I${PREFIX}/include -Wall"
LDFLAGSTMP="-L${PREFIX}/lib -Wl,-R${PREFIX}/lib"
LIBSTMP="-lpthread"

RCD_SCRIPTS=	iplog

EGDIR=		${PREFIX}/share/examples/iplog

post-patch:
	cd ${WRKSRC}/src && ${SED} s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g \
		< iplog.h > iplog.h.patched && ${MV} iplog.h.patched iplog.h

do-configure:
	cd ${WRKSRC} && CFLAGS=${CFLAGSTMP} \
	LDFLAGS=${LDFLAGSTMP} \
	LIBS=${LIBSTMP} \
	MAKE=${GMAKE} \
	${SH} ./configure --prefix=${PREFIX} --prefix=${GNU_CONFIGURE_PREFIX}

do-build:
	cd ${WRKSRC} && ${GMAKE} all

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/example-iplog.conf ${EGDIR}/iplog.conf

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
