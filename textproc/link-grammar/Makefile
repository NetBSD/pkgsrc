# $NetBSD: Makefile,v 1.28 2026/11/09 17:40:03 gutteridge Exp $

PKGNAME=	${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Syntactic parsing library

.include "../../textproc/link-grammar/Makefile.common"

CONFIGURE_ARGS+=	--disable-python-bindings

PKGCONFIG_OVERRIDE+=	link-grammar.pc.in

.include "../../mk/bsd.pkg.mk"
