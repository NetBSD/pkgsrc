# $NetBSD: Makefile,v 1.20 2025/08/10 02:19:55 wen Exp $

DISTNAME=	Hash-Merge-Simple-0.052
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Hash-Merge-Simple
COMMENT=	Perl 5 module to simply merge two or more hashes recursively
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Hash/Merge/Simple/.packlist

DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone

TOOL_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
