# $NetBSD: Makefile,v 1.1 2023/01/14 10:43:18 kim Exp $
#

DISTNAME=		colorless-107
CATEGORIES=		misc
MASTER_SITES=		http://software.kimmo.suominen.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Enable colorised command output and pipe it to less
LICENSE=		2-clause-bsd

NO_CONFIGURE=		yes
MAKE_FLAGS+=		PREFIX=${PREFIX} MANDIR=${PKGMANDIR}/man1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/colorless

DOCS=			LICENSE README.md

post-install:
	cd ${WRKSRC:Q} && pax -rw ${DOCS} ${DESTDIR}${PREFIX}/share/doc/colorless

.include "../../mk/bsd.pkg.mk"
