# $NetBSD: Makefile,v 1.9 2026/11/05 15:14:09 taca Exp $

DISTNAME=	net-sftp-4.1.1
CATEGORIES=	security net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/net-ssh/net-sftp
COMMENT=	Secure FTP for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=5.0.0<9:../../security/ruby-net-ssh

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
