# $NetBSD: Makefile,v 1.3 2023/07/03 11:29:04 vins Exp $

DISTNAME=	xpipe-2.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.netmeister.org/apps/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	https://github.com/jschauma/xpipe
COMMENT=	split input and feed it into the given utility
LICENSE=	2-clause-bsd

.include "../../mk/bsd.prefs.mk"

MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xpipe	\
		${DESTDIR}${PREFIX}/bin/xpipe
	${INSTALL_MAN} ${WRKSRC}/doc/xpipe.1	\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xpipe.1

.if ${OPSYS} == "Linux"
.include "../../devel/libbsd/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
