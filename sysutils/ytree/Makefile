# $NetBSD: Makefile,v 1.5 2023/11/06 22:07:51 fcambus Exp $

DISTNAME=	ytree-2.05
CATEGORIES=	sysutils
MASTER_SITES=	https://www.han.de/~werner/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.han.de/~werner/ytree.html
COMMENT=	File manager similar to DOS Xtree
LICENSE=	gnu-gpl-v2

BUILD_TARGET=	ytree

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LDFLAGS+=	${BUILDLINK_LDADD.curses} -lcompat_p -lreadline
.elif ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly" || \
    ${OPSYS} == "OpenBSD"
LDFLAGS+=	${BUILDLINK_LDADD.curses} -lcompat -lreadline
.else
LDFLAGS+=	${BUILDLINK_LDADD.curses} -lreadline
.endif

MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ytree \
		${DESTDIR}${PREFIX}/bin/ytree
	${INSTALL_MAN} ${WRKSRC}/ytree.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ytree.1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
