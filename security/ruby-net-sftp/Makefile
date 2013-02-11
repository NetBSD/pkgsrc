# $NetBSD: Makefile,v 1.4 2013/02/11 02:07:37 taca Exp $

DISTNAME=	net-sftp-2.1.1
CATEGORIES=	net security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/net-ssh
COMMENT=	Secure FTP for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=2.6.5:../../security/ruby-net-ssh

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
