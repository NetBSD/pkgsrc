# $NetBSD: Makefile,v 1.7 2005/03/24 21:12:59 wiz Exp $

DISTNAME=	icmp-0.2.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net ruby
MASTER_SITES=	http://www.notwork.org/~gotoyuzo/ruby/src/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Ruby module for handling ICMP packets

USE_RUBY_INSTALL=	yes
NO_BUILD=		yes
REPLACE_RUBY=		sample/ping.rb sample/traceroute.rb
EXAMPLES=		sample/ping.rb sample/traceroute.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/icmp
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/icmp
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
