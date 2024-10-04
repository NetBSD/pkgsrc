# $NetBSD: Makefile,v 1.28 2024/10/04 07:00:25 wen Exp $

DISTNAME=	autobox-v3.0.2
PKGNAME=	p5-${DISTNAME:S/v//}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=autobox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/autobox
COMMENT=	Perl 5 module to add methods on native types
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Scope-Guard>=0.20:../../devel/p5-Scope-Guard
DEPENDS+=	p5-IPC-System-Simple-[0-9]*:../../devel/p5-IPC-System-Simple

PERL5_PACKLIST=	auto/autobox/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
