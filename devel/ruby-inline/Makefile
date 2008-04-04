# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:17:28 jlam Exp $

DISTNAME=	RubyInline-3.6.7
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/^Ruby//:tl}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zenspider.com/ZSS/Products/RubyInline/
COMMENT=	Embed C/C++ code directly in Ruby

DEPENDS+=	hoe>=1.5.1:../../devel/hoe

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
