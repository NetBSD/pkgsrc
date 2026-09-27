# $NetBSD: Makefile,v 1.26 2026/09/27 11:38:53 tnn Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Syntactic parsing library

.include "../../textproc/link-grammar/Makefile.common"

CONFIGURE_ARGS+=	--disable-python-bindings

PKGCONFIG_OVERRIDE+=	link-grammar.pc.in

.include "../../mk/bsd.pkg.mk"
