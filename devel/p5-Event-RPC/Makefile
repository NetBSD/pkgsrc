# $NetBSD: Makefile,v 1.4 2008/10/19 19:17:53 he Exp $
#

DISTNAME=	Event-RPC-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.exit1.org/packages/Event-RPC/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.exit1.org/Event-RPC/
COMMENT=	Event based transparent Client/Server RPC framework

DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL

PERL5_PACKLIST=	auto/Event/RPC/.packlist
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/p5-glib2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
