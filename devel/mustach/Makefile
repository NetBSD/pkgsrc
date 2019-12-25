# $NetBSD: Makefile,v 1.2 2019/12/25 17:34:31 sjmulder Exp $

DISTNAME=	mustach-0.99
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/jobol/mustach/-/archive/${PKGVERSION_NOREV}/

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://gitlab.com/jobol/mustach
COMMENT=	C implementation of mustache templating
LICENSE=	apache-2.0

.include "../../mk/bsd.prefs.mk"

# Workaround is portable, might as well use it everywhere.
CFLAGS+=	-DNO_OPEN_MEMSTREAM

.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
