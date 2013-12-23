# $NetBSD: Makefile,v 1.12 2013/12/23 11:57:05 wiz Exp $

DISTNAME=	tac_plus.F4.0.4.alpha
PKGNAME=	tacacs-4.0.4a
CATEGORIES=	net security
MASTER_SITES=	ftp://ftpeng.cisco.com/pub/tacacs/
#		ftp://ftp.shrubbery.net/pub/tac_plus/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.shrubbery.net/tac_plus/
COMMENT=	Cisco authentication, authorization, and accounting protocol daemon
LICENSE=	cisco-license

BUILD_TARGET=	tac_plus

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
MAKE_FLAGS+=	OS=-DSOLARIS OSLIBS="-lsocket -lnsl"
.endif

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/doc/tacacs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tac_plus ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tac_plus.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/tac_plus.8
	${INSTALL_DATA} ${WRKSRC}/users_guide ${DESTDIR}${PREFIX}/share/doc/tacacs

.include "../../mk/bsd.pkg.mk"
