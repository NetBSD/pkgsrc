# $NetBSD: Makefile,v 1.3 2021/02/03 14:35:28 taca Exp $

DISTNAME=	winrm-2.3.6
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WinRb/WinRM
COMMENT=	Ruby library for Windows Remote Management
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.1.2:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-erubi>=1.8<2:../../textproc/ruby-erubi
DEPENDS+=	${RUBY_PKGPREFIX}-gssapi>=1.2<2:../../security/ruby-gssapi
DEPENDS+=	${RUBY_PKGPREFIX}-gyoku>=1.0<2:../../textproc/ruby-gyoku
DEPENDS+=	${RUBY_PKGPREFIX}-httpclient>=2.2<3:../../www/ruby-httpclient
DEPENDS+=	${RUBY_PKGPREFIX}-logging>=1.6.1:../../devel/ruby-logging
DEPENDS+=	${RUBY_PKGPREFIX}-nori>=2.0<3:../../textproc/ruby-nori
DEPENDS+=	${RUBY_PKGPREFIX}-rubyntlm>=0.6.1:../../security/ruby-rubyntlm

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
