# $NetBSD: Makefile,v 1.32 2026/05/05 13:15:45 taca Exp $

DISTNAME=	ruby_smb-3.3.19
CATEGORIES=	net

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/ruby_smb
COMMENT=	Ruby implementation of the SMB Protocol Family
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-bindata>=2.4.15:../../devel/ruby-bindata
DEPENDS+=	${RUBY_PKGPREFIX}-windows_error>=0.1.4:../../misc/ruby-windows_error
DEPENDS+=	${RUBY_PKGPREFIX}-rubyntlm>=0.6.5:../../security/ruby-rubyntlm
DEPENDS+=	${RUBY_PKGPREFIX}-openssl-ccm-[0-9]*:../../security/ruby-openssl-ccm
DEPENDS+=	${RUBY_PKGPREFIX}-openssl-cmac-[0-9]*:../../security/ruby-openssl-cmac

OVERRIDE_GEMSPEC+=	bindata>=2.4.15

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
