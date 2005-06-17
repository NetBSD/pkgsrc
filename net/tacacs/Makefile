# $NetBSD: Makefile,v 1.6 2005/06/17 03:50:28 jlam Exp $
#

DISTNAME=	tac_plus.F4.0.4.alpha
PKGNAME=	tacacs-4.0.4a
CATEGORIES=	net security
MASTER_SITES=	ftp://ftpeng.cisco.com/pub/tacacs/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gazi.edu.tr/~devrim/tacacs/
COMMENT=	Cisco authentication, authorization, and accounting protocol daemon

BUILD_TARGET=	tac_plus

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
MAKE_FLAGS+=	OS=-DSOLARIS OSLIBS="-lsocket -lnsl"
.endif

INSTALLATION_DIRS=	man/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tac_plus ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tac_plus.1 ${PREFIX}/man/man8/tac_plus.8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tacacs
	${INSTALL_DATA} ${WRKSRC}/users_guide ${PREFIX}/share/doc/tacacs

.include "../../mk/bsd.pkg.mk"
