# $NetBSD: Makefile,v 1.9 2012/10/23 19:51:24 asau Exp $
#

DISTNAME=		sredird-2.0.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.pcmicro.com/sredird/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.pcmicro.com/sredird/
COMMENT=		RFC2217 compliant serial port redirector

MAKE_FLAGS+=		CC=${CC:Q} CFLAGS=${CFLAGS:M*:Q}
BUILD_TARGET=		sredird
INSTALLATION_DIRS=	libexec share/doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sredird ${DESTDIR}${PREFIX}/libexec/sredird
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/sredird.README

.include "../../mk/bsd.pkg.mk"
