# $NetBSD: Makefile,v 1.8 2013/03/07 15:09:45 taca Exp $

DISTNAME=	ruby-debug-ide-0.4.16
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/debug-commons/
COMMENT=	IDEs interface to ruby-debug
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-debug-base-[0-9]*:../../devel/ruby-debug-base

#
# for 1.9, need ruby-debug-base-19
#
RUBY_VERSION_SUPPORTED= 18

OVERRIDE_GEMSPEC=	:extensions ext/mkrf_conf.rb= :files ext/mkrf_conf.rb=

pre-configure:
	${RM} -fr ${WRKSRC}/ext

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
