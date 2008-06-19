# $NetBSD: Makefile,v 1.9 2008/06/19 14:53:07 taca Exp $

DISTNAME=	icmp-0.2.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	net ruby
MASTER_SITES=	http://www.notwork.org/~gotoyuzo/ruby/src/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Ruby module for handling ICMP packets

USE_RUBY_INSTALL=	yes
NO_BUILD=		yes
REPLACE_RUBY=		sample/ping.rb sample/traceroute.rb
EXAMPLES=		sample/ping.rb sample/traceroute.rb
INSTALLATION_DIRS=	${RUBY_EG}/icmp

post-install:
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_EG}/icmp
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
