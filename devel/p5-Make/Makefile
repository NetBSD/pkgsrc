# $NetBSD: Makefile,v 1.38 2022/06/28 11:32:43 wiz Exp $

DISTNAME=	Make-2.011
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Make/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.ni-s.u-net.com/
COMMENT=	Perl5 module implementing 'make' in Perl
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Graph>=0.9712:../../devel/p5-Graph

TEST_DEPENDS+=	p5-Test-Compile-[0-9]*:../../devel/p5-Test-Compile \
		p5-Test-Snapshot-[0-9]*:../../devel/p5-Test-Snapshot

PERL5_PACKLIST=		auto/Make/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
