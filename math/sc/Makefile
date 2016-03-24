# $NetBSD: Makefile,v 1.19 2016/03/24 10:53:16 youri Exp $

DISTNAME=		sc-7.16_1.0.1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=n-t-roff/}

MAINTAINER=		carsten.kunze@arcor.de
HOMEPAGE=		https://github.com/n-t-roff/sc
COMMENT=		Curses-based spreadsheet program
LICENSE=		public-domain

MAKE_JOBS_SAFE=		no
HAS_CONFIGURE=		yes

USE_TOOLS+=		yacc

MAKE_FLAGS=		prefix=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 \
			DOBACKUPS=
INSTALLATION_DIRS=	bin lib ${PKGMANDIR}/man1 share/${name}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
