# $NetBSD: Makefile,v 1.6 2015/09/26 23:37:45 taca Exp $

DISTNAME=	net-sftp-2.1.2
CATEGORIES=	net security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/net-ssh/net-sftp
COMMENT=	Secure FTP for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=2.6.5:../../security/ruby-net-ssh

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
