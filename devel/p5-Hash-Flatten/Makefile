# $NetBSD: Makefile,v 1.20 2024/11/16 12:04:22 wiz Exp $
#

DISTNAME=	Hash-Flatten-1.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Hash-Flatten
COMMENT=	Perl 5 module to flatten/unflatten complex data hashes
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	p5-Log-Trace-[0-9]*:../../devel/p5-Log-Trace
TOOL_DEPENDS+=	p5-Test-Assertions-[0-9]*:../../devel/p5-Test-Assertions

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Hash/Flatten/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
