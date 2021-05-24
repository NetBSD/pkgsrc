# $NetBSD: Makefile,v 1.28 2021/05/24 19:50:04 wiz Exp $

DISTNAME=	Algorithm-Merge-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Algorithm-Merge
COMMENT=	Perl module providing diff3(1)-like functionality
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Algorithm-Diff-[0-9]*:../../devel/p5-Algorithm-Diff

PERL5_PACKLIST=		auto/Algorithm/Merge/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
