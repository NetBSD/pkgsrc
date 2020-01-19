# $NetBSD: Makefile,v 1.1 2020/01/19 15:35:47 taca Exp $

DISTNAME=	train-winrm-0.2.6
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
