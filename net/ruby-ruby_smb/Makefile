# $NetBSD: Makefile,v 1.4 2018/09/23 15:59:57 taca Exp $

DISTNAME=	ruby_smb-1.0.4
CATEGORIES=	net

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/ruby_smb
COMMENT=	Ruby implementation of the SMB Protocol Family
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-bindata-[0-9]*:../../devel/ruby-bindata
DEPENDS+=	${RUBY_PKGPREFIX}-windows_error-[0-9]*:../../misc/ruby-windows_error
DEPENDS+=	${RUBY_PKGPREFIX}-rubyntlm-[0-9]*:../../security/ruby-rubyntlm

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
