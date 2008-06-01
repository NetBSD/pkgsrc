# $NetBSD: Makefile,v 1.2 2008/06/01 19:41:51 abs Exp $
#

DISTNAME=	Event-RPC-0.90
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.exit1.org/packages/Event-RPC/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.exit1.org/Event-RPC/
COMMENT=	Event based transparent Client/Server RPC framework

DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Event/RPC/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
