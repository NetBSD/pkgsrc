# $NetBSD: Makefile,v 1.17 2023/12/12 11:35:46 zafer Exp $

DISTNAME=	lbrate-1.1
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	https://ibiblio.org/pub/linux/utils/compress/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://rus.members.beeb.net/lbrate.html
COMMENT=	Extract/decompress CP/M LBR archives

MAKE_FLAGS+=	PREFIX=${PREFIX:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/lbrate

post-install:
.for f in COPYING ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/lbrate
.endfor

.include "../../mk/bsd.pkg.mk"
