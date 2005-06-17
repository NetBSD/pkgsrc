# $NetBSD: Makefile,v 1.4 2005/06/17 03:50:35 jlam Exp $
#

DISTNAME=		sredird-2.0.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.pcmicro.com/sredird/

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://www.pcmicro.com/sredird/
COMMENT=		RFC2217 compliant serial port redirector


MAKE_FLAGS=		CC="${CC}" CFLAGS="${CFLAGS}"
BUILD_TARGET=		sredird
INSTALLATION_DIRS=	libexec share/doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sredird ${PREFIX}/libexec/sredird
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sredird.README

.include "../../mk/bsd.pkg.mk"
