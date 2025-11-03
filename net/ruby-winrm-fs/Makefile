# $NetBSD: Makefile,v 1.3 2025/11/03 07:27:50 taca Exp $

DISTNAME=	winrm-fs-1.3.5
PKGREVISION=	1
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WinRb/winrm-fs
COMMENT=	WinRM File System
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-zip24>=2.0<3:../../archivers/ruby-zip24
DEPENDS+=	${RUBY_PKGPREFIX}-winrm>=2.0<3:../../net/ruby-winrm

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
