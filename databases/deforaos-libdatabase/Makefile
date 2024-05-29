# $NetBSD: Makefile,v 1.42 2024/05/29 16:31:39 adam Exp $

DISTNAME=	libDatabase-${PKGVERSION_NOREV}
PKGNAME=	deforaos-libdatabase-0.1.0
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Database/src/libDatabase/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS libDatabase
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
AUTO_MKDIRS=	yes

#TEST_TARGET=	tests

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != "share/man"
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/database.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/database.html
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/database.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/database.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.include "../../devel/deforaos-configure/deforaos-configure.mk"
.include "../../devel/deforaos-libsystem/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk" # this one defines PGSQL_VERSION among others
.include "../../databases/postgresql${PGSQL_VERSION}-client/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.32nb9
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
