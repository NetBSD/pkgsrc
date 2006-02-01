# $NetBSD: Makefile,v 1.15 2006/02/01 17:38:01 tv Exp $

DISTNAME=		cbmconvert-2.1.2
CATEGORIES=		converters archivers
MASTER_SITES=		ftp://ftp.zimmers.net/pub/cbm/crossplatform/converters/unix/

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Converts files to and from various C64/C128/CBM formats

MAKEFILE=		Makefile.unix
MAKE_FLAGS+=		CFLAGS=${CFLAGS:M*:Q}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/cbmconvert

do-install:
.for f in cbmconvert disk2zip zip2disk
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${PREFIX}/${PKGMANDIR}/man1/
.endfor
	${INSTALL_DATA} ${WRKSRC}/cbmconvert.html ${PREFIX}/share/doc/cbmconvert/

.include "../../mk/bsd.pkg.mk"
