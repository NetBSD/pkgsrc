# $NetBSD: Makefile,v 1.2 2004/12/03 15:15:10 wiz Exp $
#

DISTNAME=		sredird-2.0.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.pcmicro.com/sredird/

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://www.pcmicro.com/sredird/
COMMENT=		RFC2217 compliant serial port redirector

USE_BUILDLINK3=		yes

MAKE_FLAGS=		CC="${CC}" CFLAGS="${CFLAGS}"
BUILD_TARGET=		sredird

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sredird ${PREFIX}/libexec/sredird
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sredird.README

.include "../../mk/bsd.pkg.mk"
