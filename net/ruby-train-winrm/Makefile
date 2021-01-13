# $NetBSD: Makefile,v 1.2 2021/01/13 14:48:25 taca Exp $

DISTNAME=	train-winrm-0.2.11
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/inspec/train-winrm
COMMENT=	Windows WinRM API Transport for Train
LICENSE=	apache-2.0


DEPENDS+=	${RUBY_PKGPREFIX}-winrm>=2.0<3:../../net/ruby-winrm
DEPENDS+=	${RUBY_PKGPREFIX}-winrm-fs>=1.0<2:../../net/ruby-winrm-fs

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
