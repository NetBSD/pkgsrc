# $NetBSD: Makefile,v 1.17 2008/06/22 16:09:32 taca Exp $

DISTNAME=	tmail-1.2.3.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	mail

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://tmail.rubyforge.org/
COMMENT=	Mail manipulating library for Ruby including MIME multipart support

GEM_BUILD=	gemspec

# Add a directory that would be created if the setup.rb script was run.
post-extract:
	cd ${WRKSRC} && mkdir doc

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
