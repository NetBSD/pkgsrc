# $NetBSD: Makefile,v 1.1 2014/10/01 13:21:52 fhajny Exp $

DISTNAME=	rugged-0.21.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/libgit2/rugged
COMMENT=	Ruby bindings to libgit2
LICENSE=	mit

CONFIGURE_ARGS+=	--use-system-libraries

.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
