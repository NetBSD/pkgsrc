# $NetBSD: Makefile,v 1.13 2015/02/21 11:37:52 mef Exp $
#

DISTNAME=	Net-GitHub-0.72
PKGNAME=	p5-${DISTNAME}
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
DEPENDS+=	p5-JSON-Any-[0-9]*:../../converters/p5-JSON-Any
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
