# $NetBSD: Makefile,v 1.15 2012/06/14 15:16:07 taca Exp $

DISTNAME=	facter-1.6.10
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://www.puppetlabs.com/puppet/related-projects/facter/
COMMENT=	Cross-platform Ruby library for retrieving facts from OS
LICENSE=	gnu-gpl-v2

CONFLICTS+=	ruby[1-9][0-9]-facter-[0-9]*

pre-configure:
	${CHMOD} -R g-w ${WRKSRC}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
