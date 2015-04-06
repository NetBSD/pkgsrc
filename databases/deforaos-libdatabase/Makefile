# $NetBSD: Makefile,v 1.9 2015/04/06 08:17:22 adam Exp $

DISTNAME=	libDatabase-0.0.0
PKGNAME=	deforaos-libdatabase-0.0.0
PKGREVISION=	7
CATEGORIES=	databases
MASTER_SITES=	http://www.defora.org/os/download/download/4287/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS libDatabase

LICENSE=	gnu-gpl-v3

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../devel/deforaos-libsystem/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk" # this one defines PGSQL_VERSION among others
.include "../../databases/postgresql${PGSQL_VERSION}-client/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.20
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
