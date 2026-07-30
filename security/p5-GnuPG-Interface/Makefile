# $NetBSD: Makefile,v 1.45 2026/07/30 22:57:00 wen Exp $

DISTNAME=		GnuPG-Interface-1.07
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BP/BPS/}

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		https://gnupg-interface.sourceforge.net/
HOMEPAGE=		https://metacpan.org/release/GnuPG-Interface
COMMENT=		Perl interface to GnuPG
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=		p5-MooX-late>=0.100nb1:../../devel/p5-MooX-late
DEPENDS+=		p5-MooX-HandlesVia-[0-9]*:../../devel/p5-MooX-HandlesVia

PERL5_PACKLIST=		auto/GnuPG/Interface/.packlist

.include "options.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
