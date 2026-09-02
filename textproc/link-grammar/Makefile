# $NetBSD: Makefile,v 1.24 2026/09/02 19:04:45 wiz Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Syntactic parsing library

.include "../../textproc/link-grammar/Makefile.common"

CONFIGURE_ARGS+=	--disable-python-bindings

PKGCONFIG_OVERRIDE+=	link-grammar.pc.in

.include "../../mk/bsd.pkg.mk"
