# $NetBSD: Makefile,v 1.27 2023/07/04 02:10:39 wen Exp $
#

DISTNAME=		Number-Format-1.76
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Number-Format
COMMENT=		Perl extension for formatting numbers
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Number/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
