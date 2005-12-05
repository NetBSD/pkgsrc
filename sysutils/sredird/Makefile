# $NetBSD: Makefile,v 1.5 2005/12/05 20:51:01 rillig Exp $
#

DISTNAME=		sredird-2.0.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.pcmicro.com/sredird/

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://www.pcmicro.com/sredird/
COMMENT=		RFC2217 compliant serial port redirector


MAKE_FLAGS+=		CC=${CC:Q} CFLAGS=${CFLAGS:M*:Q}
BUILD_TARGET=		sredird
INSTALLATION_DIRS=	libexec share/doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sredird ${PREFIX}/libexec/sredird
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sredird.README

.include "../../mk/bsd.pkg.mk"
