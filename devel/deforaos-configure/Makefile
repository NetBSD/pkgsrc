# $NetBSD: Makefile,v 1.14 2023/06/06 12:40:36 riastradh Exp $

DISTNAME=	configure-0.4.3
PKGNAME=	deforaos-configure-0.4.3
CATEGORIES=	devel
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Devel/src/configure/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS automated Makefile generation tool

LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
AUTO_MKDIRS=	yes

#TEST_TARGET=	tests

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
LDFLAGS+=	-lm
.endif

.if ${PKGMANDIR} != "share/man"
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/configure.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/configure.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html5/project.conf.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html5/project.conf.html
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/configure.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/configure.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man5/project.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/project.conf.5
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html5
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man5
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.include "../../devel/deforaos-libsystem/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
