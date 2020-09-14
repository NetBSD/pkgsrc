# $NetBSD: Makefile,v 1.2 2020/09/14 13:51:20 taca Exp $

DISTNAME=	winrm-fs-1.3.5
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WinRb/winrm-fs
COMMENT=	WinRM File System
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-zip>=1.1:../../archivers/ruby-zip
DEPENDS+=	${RUBY_PKGPREFIX}-winrm>=2.0<3:../../net/ruby-winrm

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
