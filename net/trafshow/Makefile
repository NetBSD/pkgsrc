# $NetBSD: Makefile,v 1.11 2001/08/27 14:35:13 tron Exp $

DISTNAME=	trafshow-3.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nsk.su/pub/RinetSoftware/
EXTRACT_SUFX=	.tgz

PATCHFILES=	trafshow-31-v6-20010322a.diff.gz
PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCH_DIST_STRIP+=	-p1

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://soft.risp.ru/trafshow/index.shtml
COMMENT=	Full screen visualization of the network traffic

BUILD_DEPENDS+=	autoconf>=2.13:../../devel/autoconf

GNU_CONFIGURE=	yes
ALL_TARGET=	trafshow

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	USE_INET6

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CPPFLAGS+=	-DINET6
.endif

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trafshow ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/trafshow.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/trafshow
	${INSTALL_DATA} ${WRKSRC}/.trafshow \
		${PREFIX}/share/examples/trafshow/trafshow

.include "../../mk/bsd.pkg.mk"
