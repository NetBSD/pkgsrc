# $NetBSD: Makefile,v 1.15 2014/10/09 14:05:52 wiz Exp $

DISTNAME=	lbrate-1.1
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/Linux/utils/compress/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rus.members.beeb.net/lbrate.html
COMMENT=	Extract/decompress CP/M LBR archives

MAKE_FLAGS+=	PREFIX=${PREFIX:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/lbrate

post-install:
.for f in COPYING ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/lbrate
.endfor

.include "../../mk/bsd.pkg.mk"
