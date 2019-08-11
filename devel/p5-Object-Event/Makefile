# $NetBSD: Makefile,v 1.14 2019/08/11 13:20:03 wiz Exp $
#

DISTNAME=		Object-Event-1.23
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Object-Event
COMMENT=		Perl 5 class that provides an event callback interface
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Object/Event/.packlist

DEPENDS+=	p5-AnyEvent>=3.5:../../devel/p5-AnyEvent
DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
