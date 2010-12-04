# $NetBSD: Makefile,v 1.7 2010/12/04 03:55:29 taca Exp $

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

pre-configure:
	${RM} -fr ${WRKSRC}/ext

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
