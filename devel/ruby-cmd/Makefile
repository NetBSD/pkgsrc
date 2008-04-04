# $NetBSD: Makefile,v 1.7 2008/04/04 15:30:00 jlam Exp $

DISTNAME=	cmd-0.7.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/cmd/
COMMENT=	Library for building line-oriented command interpreters

DEPENDS+=	${RUBY_PKGPREFIX}-readline-[0-9]*:../../devel/ruby-readline

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
