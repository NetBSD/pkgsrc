# $NetBSD: Makefile,v 1.8 2012/03/08 01:08:41 joerg Exp $

DISTNAME=	unworkable-0.51
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	# http://p2presearch.com/unworkable/dist/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://p2presearch.com/unworkable/
COMMENT=	BSD-licensed command-line torrent client

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	yacc
WRKSRC=		${WRKDIR}/unworkable
MAKE_FILE=	BSDmakefile

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/cat1

post-configure:
	cp ${WRKSRC}/openbsd-compat/sha1.c ${WRKSRC}
	cp ${WRKSRC}/openbsd-compat/strtonum.c ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unworkable ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/unworkable.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/libevent/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
