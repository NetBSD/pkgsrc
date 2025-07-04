# $NetBSD: Makefile,v 1.36 2025/07/04 08:48:28 wiz Exp $

DISTNAME=	Text-Diff-1.45
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	High-level text diffing module for Perl
HOMEPAGE=	https://metacpan.org/release/Text-Diff
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-Algorithm-Diff>=1.19:../../devel/p5-Algorithm-Diff

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Text/Diff/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
