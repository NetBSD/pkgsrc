# $NetBSD: Makefile,v 1.1 2022/09/18 22:38:44 jschauma Exp $

DISTNAME=	xpipe-2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.netmeister.org/apps/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	https://github.com/jschauma/xpipe
COMMENT=	split input and feed it into the given utility
LICENSE=	2-clause-bsd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux
LDFLAGS+=       -lbsd
CFLAGS+=	-I${PREFIX}/bsd
.endif

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
