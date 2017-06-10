# $NetBSD: Makefile,v 1.1 2017/06/10 16:38:25 taca Exp $

DISTNAME=	specinfra-2.68.0
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mizzy/specinfra
COMMENT=	Common layer for serverspec and itamae
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-scp>=0:../../security/ruby-net-scp

OVERRIDE_GEMSPEC+=	sfl:

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} == "21" || ${RUBY_VER} == "22"
DEPENDS+=	${RUBY_PKGPREFIX}-net-telnet>=0:../../net/ruby-net-telnet
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
