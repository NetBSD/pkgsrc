# $NetBSD: Makefile,v 1.21 2023/11/11 12:49:18 taca Exp $

DISTNAME=	ruby_smb-3.2.6
CATEGORIES=	net

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/ruby_smb
COMMENT=	Ruby implementation of the SMB Protocol Family
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-bindata-[0-9]*:../../devel/ruby-bindata
DEPENDS+=	${RUBY_PKGPREFIX}-windows_error>=0.1.4:../../misc/ruby-windows_error
DEPENDS+=	${RUBY_PKGPREFIX}-rubyntlm-[0-9]*:../../security/ruby-rubyntlm
DEPENDS+=	${RUBY_PKGPREFIX}-openssl-ccm-[0-9]*:../../security/ruby-openssl-ccm
DEPENDS+=	${RUBY_PKGPREFIX}-openssl-cmac-[0-9]*:../../security/ruby-openssl-cmac

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
