# $NetBSD: Makefile,v 1.26 2023/06/06 12:40:36 riastradh Exp $

DISTNAME=	libSystem-0.4.3
PKGNAME=	deforaos-libsystem-0.4.3
CATEGORIES=	devel
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/System/src/libSystem/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS core system library
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=	libtool-[0-9]*:../../devel/libtool

LDFLAGS+=	${BUILDLINK_LDADD.dl}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	INSTALL=${INSTALL:Q}
AUTO_MKDIRS=	yes

#TEST_TARGET=	tests

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != "share/man"
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/configctl.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/configctl.html
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/configctl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/configctl.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

REPLACE_SH=	tests/tests.sh

DL_AUTO_VARS=	yes
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
