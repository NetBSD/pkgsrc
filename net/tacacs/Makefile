# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 17:26:42 rh Exp $
#

DISTNAME=	tac_plus.F4.0.4.alpha
PKGNAME=	tacacs-4.0.4a
CATEGORIES=	net security
MASTER_SITES=	ftp://ftpeng.cisco.com/pub/tacacs/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gazi.edu.tr/~devrim/tacacs/

ALL_TARGET=	tac_plus

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tac_plus ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tac_plus.1 ${PREFIX}/man/man8/tac_plus.8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tacacs
	${INSTALL_DATA} ${WRKSRC}/users_guide ${PREFIX}/share/doc/tacacs

.include "../../mk/bsd.pkg.mk"
