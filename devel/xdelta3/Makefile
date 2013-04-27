# $NetBSD: Makefile,v 1.10 2013/04/27 12:08:34 shattered Exp $
#

DISTNAME=		xdelta3-3.0.6
CATEGORIES=		devel
MASTER_SITES=		http://xdelta.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xdelta.org/
COMMENT=		Enhanced diff that works on binary files (version 3.x)
LICENSE=		gnu-gpl-v2

BUILD_TARGET=		xdelta3
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin share/doc/xdelta3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdelta3 ${DESTDIR}${PREFIX}/bin/xdelta3
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xdelta3

do-test:
	${WRKSRC}/xdelta3 test

.include "../../mk/bsd.pkg.mk"
