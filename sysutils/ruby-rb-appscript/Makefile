# $NetBSD: Makefile,v 1.7 2020/03/20 11:58:22 nia Exp $

DISTNAME=	rb-appscript-0.6.1
PKGREVISION=	1
CATEGORIES=	sysutils ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://appscript.sourceforge.net/
COMMENT=	Ruby Apple event bridge

ONLY_FOR_PLATFORM=	Darwin-*-*

GEM_CLEANBUILD=	Makefile *.o *.time ae.${RUBY_DLEXT} .RUBY*.time

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
