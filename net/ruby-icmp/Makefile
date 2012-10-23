# $NetBSD: Makefile,v 1.12 2012/10/23 17:19:06 asau Exp $

DISTNAME=	icmp-0.2.2
PKGREVISION=	3
CATEGORIES=	net ruby
MASTER_SITES=	http://www.notwork.org/~gotoyuzo/ruby/src/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Ruby module for handling ICMP packets
LICENSE=	2-clause-bsd

USE_RUBY_SETUP=		yes
USE_RUBY_SETUP_PKG=	yes
NO_BUILD=		yes
REPLACE_RUBY=		sample/ping.rb sample/traceroute.rb
EXAMPLES=		sample/ping.rb sample/traceroute.rb
INSTALLATION_DIRS=	${RUBY_EG}/icmp ${RUBY_VENDORLIB}

post-install:
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_EG}/icmp
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
