# $NetBSD: Makefile,v 1.29 2024/11/16 12:06:48 wiz Exp $
#

DISTNAME=		Number-Format-1.76
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Number/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Number-Format
COMMENT=		Perl extension for formatting numbers
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Number/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
