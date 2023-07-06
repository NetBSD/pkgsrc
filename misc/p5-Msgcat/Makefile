# $NetBSD: Makefile,v 1.33 2023/07/06 09:41:00 wiz Exp $
#

DISTNAME=		Msgcat-1.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		15
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Msgcat
COMMENT=		Perl5 module to use the message catalog functions

PERL5_PACKLIST=		auto/Locale/Msgcat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
