# $NetBSD: Makefile,v 1.14 2019/08/11 13:22:27 wiz Exp $

DISTNAME=		WebService-MusicBrainz-1.0.4
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=WebService/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/WebService-MusicBrainz
COMMENT=		Perl 5 module providing an interface to MusicBrainz
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Mojolicious-[0-9]*:../../www/p5-Mojolicious

PERL5_PACKLIST=		auto/WebService/MusicBrainz/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
