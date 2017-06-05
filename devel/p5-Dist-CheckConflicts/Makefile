# $NetBSD: Makefile,v 1.11 2017/06/05 14:22:54 ryoon Exp $

DISTNAME=	Dist-CheckConflicts-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Dist/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Dist-CheckConflicts/
COMMENT=	Perl 5 module to declare version conflicts for your dist
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_PACKLIST=		auto/Dist/CheckConflicts/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
