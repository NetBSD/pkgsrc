# $NetBSD: Makefile,v 1.22 2023/10/15 06:39:25 ryoon Exp $

PKGNAME=	${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Syntactic parsing library

.include "../../textproc/link-grammar/Makefile.common"

CONFIGURE_ARGS+=	--disable-python-bindings

PKGCONFIG_OVERRIDE+=	link-grammar.pc.in

.include "../../mk/bsd.pkg.mk"
