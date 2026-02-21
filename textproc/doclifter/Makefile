# $NetBSD: Makefile,v 1.32 2026/02/21 20:18:51 wiz Exp $

DISTNAME=	doclifter-2.22
CATEGORIES=	textproc
# doesn't provide the distfile for ftp(1)
MASTER_SITES=	# http://catb.org/~esr/doclifter/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://catb.org/~esr/doclifter/
COMMENT=	Translates documents written in troff macros to DocBook
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake

NO_BUILD=	yes

REPLACE_PYTHON=		doclifter manlifter

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

# https://gitlab.com/esr/doclifter/-/issues/7
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
