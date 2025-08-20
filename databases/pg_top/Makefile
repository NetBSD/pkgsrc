# $NetBSD: Makefile,v 1.6 2025/08/20 11:34:49 wiz Exp $

DISTNAME=	pg_top-4.0.0
CATEGORIES=	databases
MASTER_SITES=	https://pg_top.gitlab.io/source/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pg_top.gitlab.io/
COMMENT=	Monitoring program similar to top for PostgreSQL

NOT_FOR_PLATFORM=	NetBSD-*-*

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../devel/libbsd/buildlink3.mk"
.endif
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
