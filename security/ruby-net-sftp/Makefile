# $NetBSD: Makefile,v 1.8 2023/01/19 15:01:17 taca Exp $

DISTNAME=	net-sftp-4.0.0
CATEGORIES=	security net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/net-ssh/net-sftp
COMMENT=	Secure FTP for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=5.0.0:../../security/ruby-net-ssh

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
