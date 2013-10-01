# $NetBSD: Makefile,v 1.4 2013/10/01 15:24:02 taca Exp $

DISTNAME=	rb-appscript-0.6.1
PKGREVISION=	1
CATEGORIES=	sysutils ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/rb-appscript/
COMMENT=	Ruby Apple event bridge

ONLY_FOR_PLATFORM=	Darwin-*-*

GEM_CLEANBUILD=	Makefile *.o *.time ae.${RUBY_DLEXT} .RUBY*.time

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
