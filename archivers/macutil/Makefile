# $NetBSD: Makefile,v 1.25 2012/09/11 19:46:57 asau Exp $

DISTNAME=		macutil2.0b3
PKGNAME=		macutil-2.0b3
CATEGORIES=		archivers
MASTER_SITES=		ftp://ftp.cwi.nl/pub/dik/
EXTRACT_SUFX=		.shar.Z

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Create & extract Mac archive files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_FILE=		makefile
MAKE_ENV+=		CF=${CFLAGS:M*:Q}

WRKSRC=			${WRKDIR}/macutil

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/macunpack/macunpack \
			   ${WRKSRC}/hexbin/hexbin \
			   ${WRKSRC}/mixed/macsave \
			   ${WRKSRC}/mixed/macstream \
			   ${WRKSRC}/binhex/binhex \
			   ${WRKSRC}/comm/tomac \
			   ${WRKSRC}/comm/frommac \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/macunpack.1 \
		       ${WRKSRC}/man/hexbin.1 \
		       ${WRKSRC}/man/macsave.1 \
		       ${WRKSRC}/man/macstream.1 \
		       ${WRKSRC}/man/binhex.1 \
		       ${WRKSRC}/man/tomac.1 \
		       ${WRKSRC}/man/frommac.1 \
		       ${WRKSRC}/man/macutil.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
