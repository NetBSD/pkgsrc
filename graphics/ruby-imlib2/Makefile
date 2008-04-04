# $NetBSD: Makefile,v 1.14 2008/04/04 15:30:01 jlam Exp $

DISTNAME=	imlib2-ruby-0.5.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://pablotron.org/files/gems/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.pablotron.org/software/imlib2-ruby/
COMMENT=	Imlib2 bindings for Ruby

GEM_NAME=	${DISTNAME:S/imlib2-ruby/Imlib2-Ruby/}
GEM_BUILD=	gemspec
GEM_CLEANBUILD=	Makefile *.o imlib2.${RUBY_DLEXT} mkmf.log

RUBY_REQD=		1.8.0

.include "../../misc/rubygems/rubygem.mk"

BUILDLINK_API_DEPENDS.imlib2+=      imlib2>=1.2.0nb2

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
