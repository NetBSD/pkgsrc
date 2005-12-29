# $NetBSD: Makefile,v 1.12 2005/12/29 06:22:04 jlam Exp $

DISTNAME=		tspc-2.1.1-src
PKGNAME=		${DISTNAME:S/-src//}
CATEGORIES=		net
MASTER_SITES=		http://www.hexago.com/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ghen@NetBSD.org
COMMENT=		Tunnel Setup Protocol Client for Freenet6
HOMEPAGE=		http://www.hexago.com/

ONLY_FOR_PLATFORM=	NetBSD-*-*
ONLY_FOR_PLATFORM+=	OpenBSD-*-*
ONLY_FOR_PLATFORM+=	FreeBSD-*-*
ONLY_FOR_PLATFORM+=	Linux-*-*
ONLY_FOR_PLATFORM+=	Darwin-*-*
ONLY_FOR_PLATFORM+=	SunOS-*-*

.if "${OPSYS}" == "SunOS"
TARGET=			solaris
.else
TARGET=			${LOWER_OPSYS}
.endif

MAKE_ENV+=		target=${TARGET:Q}

WRKSRC=			${WRKDIR}/tspc2

CONF_FILES+=		${PREFIX}/share/examples/tspc/tspc.conf ${PKG_SYSCONFDIR}/tspc.conf
CONF_FILES_MODE=	0600

RCD_SCRIPTS=		tspc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tspc ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/man/man5/tspc.conf.5 ${PREFIX}/${PKGMANDIR}/man5/
	${INSTALL_MAN} ${WRKSRC}/man/man8/tspc.8 ${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tspc/
	${INSTALL_DATA} ${WRKSRC}/bin/tspc.conf.sample ${PREFIX}/share/examples/tspc/tspc.conf

.include "../../mk/bsd.pkg.mk"
