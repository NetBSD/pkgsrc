# $NetBSD: Makefile,v 1.1 2021/02/03 14:32:24 taca Exp $

DISTNAME=	winrm-elevated-1.2.3
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WinRb/winrm-elevated
COMMENT=	Ruby library for running commands as elevated
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-erubi>=1.8<2:../../textproc/ruby-erubi
#DEPENDS+=	${RUBY_PKGPREFIX}-winrm>=2.0<3:../../net/net/ruby-winrm
DEPENDS+=	${RUBY_PKGPREFIX}-winrm-fs>=1.0<2:../../net/ruby-winrm-fs

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
