# $NetBSD: Makefile,v 1.25 2021/05/24 19:54:33 wiz Exp $
#

DISTNAME=		Number-Format-1.75
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Number-Format
COMMENT=		Perl extension for formatting numbers
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Number/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
