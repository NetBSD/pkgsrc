# $NetBSD: Makefile,v 1.12 2008/04/04 15:30:00 jlam Exp $

DISTNAME=	activerecord-2.0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/activerecord/
COMMENT=	Object-relation mapping put on rails

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.0.2nb1:../../devel/ruby-activesupport

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
