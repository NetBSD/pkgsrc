# $NetBSD: Makefile,v 1.9 2011/08/12 17:14:42 taca Exp $

DISTNAME=	facter-1.6.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	http://reductivelabs.com/downloads/gems/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://www.puppetlabs.com/puppet/related-projects/facter/
COMMENT=	Cross-platform Ruby library for retrieving facts from OS
LICENSE=	gnu-gpl-v2

CONFLICTS+=	ruby[1-9][0-9]-facter-[0-9]*

pre-configure:
	${CHMOD} -R g-w ${WRKSRC}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
