# $NetBSD: Makefile,v 1.1.1.1 2008/03/12 23:47:05 tonnerre Exp $
#

DISTNAME=		facter-1.3.8
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		sysutils ruby
MASTER_SITES=		http://www.reductivelabs.com/downloads/facter/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://www.reductivelabs.com/projects/facter/
COMMENT=		Cross-platform Ruby library for retrieving facts from OS

NO_BUILD=		yes
USE_RUBY_INSTALL=	yes

.include "../../lang/ruby/modules.mk"

.include "../../mk/bsd.pkg.mk"
