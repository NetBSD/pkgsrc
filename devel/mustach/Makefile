# $NetBSD: Makefile,v 1.4 2020/05/19 12:09:07 nia Exp $

DISTNAME=	mustach-0.99
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/jobol/mustach/-/archive/${PKGVERSION_NOREV}/

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://gitlab.com/jobol/mustach
COMMENT=	C implementation of mustache templating
LICENSE=	apache-2.0

.include "../../mk/bsd.prefs.mk"

# Workaround is portable, might as well use it everywhere.
CFLAGS+=	-DNO_OPEN_MEMSTREAM

# install_name must be set on macOS. Upstream PR:
# https://gitlab.com/jobol/mustach/merge_requests/16
.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
	install_name_tool -id ${PREFIX}/lib/libmustach.so \
	    ${DESTDIR}${PREFIX}/lib/libmustach.so
.endif

.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
