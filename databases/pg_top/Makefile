# $NetBSD: Makefile,v 1.3 2023/08/11 09:09:09 nia Exp $

DISTNAME=	pg_top-4.0.0
CATEGORIES=	databases
MASTER_SITES=	https://pg_top.gitlab.io/source/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pg_top.gitlab.io
COMMENT=	top-like monitoring program for PostgreSQL

NOT_FOR_PLATFORM=	NetBSD-*-*

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../devel/libbsd/buildlink3.mk"
.endif
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
