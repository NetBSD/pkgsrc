# $NetBSD: Makefile,v 1.11 2008/04/04 15:30:01 jlam Exp $

DISTNAME=	actionmailer-2.0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/actionmailer/
COMMENT=	Ruby framework for designing email-service layers

DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=2.0.2nb1:../../www/ruby-actionpack

# This isn't strictly necessary as actionmailer bundles its own copy
# of tmail, but we can make use of the bugfixes in a more recent gem
# installation of tmail.
#
DEPENDS+=	${RUBY_PKGPREFIX}-tmail>=1.2.2:../../mail/ruby-tmail

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
