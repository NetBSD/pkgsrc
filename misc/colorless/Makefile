# $NetBSD: Makefile,v 1.5 2023/12/19 12:35:20 zafer Exp $
#

DISTNAME=		colorless-109
CATEGORIES=		misc
MASTER_SITES=		https://software.kimmo.suominen.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Enable colorised command output and pipe it to less
LICENSE=		2-clause-bsd

USE_TOOLS+=		pax

NO_CONFIGURE=		yes
MAKE_FLAGS+=		PREFIX=${PREFIX}
MAKE_FLAGS+=		MANDIR=${PKGMANDIR}/man1
MAKE_FLAGS+=		SHELL=${SH}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/colorless

DOCS=			LICENSE README.md

post-install:
	cd ${WRKSRC:Q} && ${PAX} -rw ${DOCS} ${DESTDIR}${PREFIX}/share/doc/colorless

.include "../../mk/bsd.pkg.mk"
