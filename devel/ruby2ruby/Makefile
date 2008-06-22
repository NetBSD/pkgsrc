# $NetBSD: Makefile,v 1.2 2008/06/22 16:07:09 taca Exp $

DISTNAME=	ruby2ruby-1.1.9
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seattlerb.rubyforge.org/
COMMENT=	Pure Ruby code from Ruby S-expressions

DEPENDS+=	${RUBY_PKGPREFIX}-parsetree-[0-9]*:../../devel/ruby-parsetree
DEPENDS+=	hoe>=1.4.0:../../devel/hoe

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
