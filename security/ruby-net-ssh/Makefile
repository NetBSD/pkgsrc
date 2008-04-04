# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:20:34 jlam Exp $

DISTNAME=	net-ssh-1.1.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	net security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://net-ssh.rubyforge.org/
COMMENT=	Secure shell for Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-needle>=1.2.0:../../devel/ruby-needle

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
