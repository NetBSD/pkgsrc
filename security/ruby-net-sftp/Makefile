# $NetBSD: Makefile,v 1.7 2021/01/18 15:23:50 taca Exp $

DISTNAME=	net-sftp-3.0.0
CATEGORIES=	security net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/net-ssh/net-sftp
COMMENT=	Secure FTP for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=5.0.0:../../security/ruby-net-ssh

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
