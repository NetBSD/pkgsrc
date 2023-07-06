# $NetBSD: Makefile,v 1.18 2023/07/06 09:39:04 wiz Exp $

DISTNAME=	Dir-Self-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Dir/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Dir-Self
COMMENT=	Perl 5 __DIR__ constant for source file's directory
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Dir/Self/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
