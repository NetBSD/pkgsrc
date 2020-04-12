# $NetBSD: Makefile,v 1.28 2020/04/12 08:28:24 adam Exp $

DISTNAME=	libDatabase-0.0.2
PKGNAME=	deforaos-libdatabase-0.0.2
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Database/src/libDatabase/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS libDatabase

LICENSE=	gnu-gpl-v3

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

.include "../../devel/deforaos-libsystem/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk" # this one defines PGSQL_VERSION among others
.include "../../databases/postgresql${PGSQL_VERSION}-client/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.20
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
