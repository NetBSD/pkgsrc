# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:20:28 jlam Exp $

DISTNAME=	net-sftp-1.1.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	net security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://net-ssh.rubyforge.org/
COMMENT=	Secure FTP for Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=1.1.0:../../security/ruby-net-ssh

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
