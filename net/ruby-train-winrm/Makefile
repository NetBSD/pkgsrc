# $NetBSD: Makefile,v 1.4 2022/08/28 04:35:24 taca Exp $

DISTNAME=	train-winrm-0.2.13
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
