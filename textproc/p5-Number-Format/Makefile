# $NetBSD: Makefile,v 1.28 2023/07/06 09:41:41 wiz Exp $
#

DISTNAME=		Number-Format-1.76
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Number-Format
COMMENT=		Perl extension for formatting numbers
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Number/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
