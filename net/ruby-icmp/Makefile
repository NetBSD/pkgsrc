# $NetBSD: Makefile,v 1.1.1.1 2001/07/01 14:26:16 taca Exp $
# FreeBSD: ports/net/ruby-icmp/Makefile,v 1.2 2000/11/02 19:06:06 knu Exp

DISTNAME=	icmp-0.1.1
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://www.notwork.org/~gotoyuzo/ruby/src/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	# not available
COMMENT=	Ruby module for handling ICMP packets

DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes

INSTALL_TARGET=	site-install

REPLACE_RUBY=	ping.rb
EXAMPLES=	ping.rb

post-install:
	${INSTALL_DATA} ${WRKSRC}/icmp.rb ${RUBY_SITELIBDIR}
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/icmp
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/icmp
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
