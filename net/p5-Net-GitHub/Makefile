# $NetBSD: Makefile,v 1.18 2017/06/05 14:24:19 ryoon Exp $
#

DISTNAME=	Net-GitHub-0.83
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-GitHub/
COMMENT=	Perl 5 interface for github.com
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Net/GitHub/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
DEPENDS+=	p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=       p5-Cache-LRU-[0-9]*:../../devel/p5-Cache-LRU

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
