# $NetBSD: Makefile,v 1.33 2020/06/08 14:18:15 wiz Exp $

DISTNAME=		GnuPG-Interface-1.00
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=GnuPG/}

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://gnupg-interface.sourceforge.net/
HOMEPAGE=		https://metacpan.org/release/GnuPG-Interface
COMMENT=		Perl interface to GnuPG
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=		p5-MooX-late>=0.100nb1:../../devel/p5-MooX-late
DEPENDS+=		p5-MooX-HandlesVia-[0-9]*:../../devel/p5-MooX-HandlesVia
# This should not be a direct dependency, but I didn't find which DEPENDS
# should pull this in instead.
DEPENDS+=		p5-Class-Tiny-[0-9]*:../../devel/p5-Class-Tiny

PERL5_PACKLIST=		auto/GnuPG/Interface/.packlist

.include "options.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
