# $NetBSD: Makefile,v 1.13 2010/01/29 23:08:33 joerg Exp $
#

DISTNAME=	golddigC3.1
PKGNAME=	golddig-3.1
CATEGORIES=	games x11
MASTER_SITES=	http://www.NetBSD.org/~chuck/gz/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast action game designed for use with X

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MAN=${DESTDIR}${PREFIX}/${PKGMANDIR}/man6

SCORE_GROUP=    games
PKG_GROUPS=     ${SCORE_GROUP}

MAKE_ENV+=              SCORE_GROUP=${SCORE_GROUP:Q}

post-build:
	for f in ${WRKSRC}/golddig.6 ${WRKSRC}/gdedit.6; do \
		${SED} "s|@PREFIX@|${PREFIX}|g" $$f > $$f.new && \
		${MV} $$f.new $$f; \
	done

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
