# $NetBSD: Makefile,v 1.1 2023/04/19 13:31:58 joerg Exp $

DISTNAME=	pg_top-4.0.0
CATEGORIES=	databases
MASTER_SITES=	https://pg_top.gitlab.io/source/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pg_top.gitlab.io
COMMENT=	top-like monitoring program for PostgreSQL

.include "../../devel/cmake/build.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
