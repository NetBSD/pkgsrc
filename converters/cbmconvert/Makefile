# $NetBSD: Makefile,v 1.18 2008/03/03 05:51:07 jlam Exp $

DISTNAME=		cbmconvert-2.1.2
CATEGORIES=		converters archivers
MASTER_SITES=		ftp://ftp.zimmers.net/pub/cbm/crossplatform/converters/unix/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Converts files to and from various C64/C128/CBM formats

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FILE=		Makefile.unix
MAKE_FLAGS+=		CFLAGS=${CFLAGS:M*:Q}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/cbmconvert

do-install:
.for f in cbmconvert disk2zip zip2disk
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor
	${INSTALL_DATA} ${WRKSRC}/cbmconvert.html \
		${DESTDIR}${PREFIX}/share/doc/cbmconvert

.include "../../mk/bsd.pkg.mk"
