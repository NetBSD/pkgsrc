# $NetBSD: Makefile,v 1.23 2025/10/23 20:39:35 wiz Exp $

PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Syntactic parsing library

.include "../../textproc/link-grammar/Makefile.common"

CONFIGURE_ARGS+=	--disable-python-bindings

PKGCONFIG_OVERRIDE+=	link-grammar.pc.in

.include "../../mk/bsd.pkg.mk"
