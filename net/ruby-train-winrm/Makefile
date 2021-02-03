# $NetBSD: Makefile,v 1.3 2021/02/03 14:29:18 taca Exp $

DISTNAME=	train-winrm-0.2.12
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/inspec/train-winrm
COMMENT=	Windows WinRM API Transport for Train
LICENSE=	apache-2.0


#DEPENDS+=	${RUBY_PKGPREFIX}-winrm>=2.3.6<3:../../net/ruby-winrm
DEPENDS+=	${RUBY_PKGPREFIX}-winrm-elevated>=1.2.2<1.3:../../net/ruby-winrm-elevated
#DEPENDS+=	${RUBY_PKGPREFIX}-winrm-fs>=1.0<2:../../net/ruby-winrm-fs

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
