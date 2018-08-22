# $NetBSD: Makefile,v 1.24 2018/08/22 09:43:57 wiz Exp $

DISTNAME=	Event-RPC-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.exit1.org/packages/Event-RPC/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.exit1.org/Event-RPC/
#HOMEPAGE=	http://search.cpan.org/dist/Event-RPC/
COMMENT=	Event based transparent Client/Server RPC framework
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Event-[0-9]*:../../devel/p5-Event
DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay

PERL5_PACKLIST=		auto/Event/RPC/.packlist

.include "../../devel/p5-glib2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
