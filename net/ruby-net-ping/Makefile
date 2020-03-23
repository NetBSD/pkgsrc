# $NetBSD: Makefile,v 1.14 2020/03/23 17:29:54 taca Exp $

DISTNAME=	net-ping-2.0.6
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chernesk/net-ping
COMMENT=	Ping interface for Ruby
LICENSE=	mit

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC+= :files net-ping-2.0.1.gem= net-ping-2.0.2.gem= \
			net-ping-2.0.5.gem=

post-patch:
	${RM} -f ${WRKSRC}/net-ping-2.0.1.gem ${WRKSRC}/net-ping-2.0.2.gem \
		 ${WRKSRC}/net-ping-2.0.5.gem

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
