# $NetBSD: Makefile,v 1.3 2017/09/11 15:53:36 taca Exp $

DISTNAME=	specinfra-2.71.2
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mizzy/specinfra
COMMENT=	Common layer for serverspec and itamae
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-scp>=0:../../security/ruby-net-scp

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} == "22"
DEPENDS+=	${RUBY_PKGPREFIX}-net-telnet>=0:../../net/ruby-net-telnet
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
