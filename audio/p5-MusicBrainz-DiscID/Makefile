# $NetBSD: Makefile,v 1.13 2023/07/06 09:38:10 wiz Exp $

DISTNAME=	MusicBrainz-DiscID-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MusicBrainz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MusicBrainz-DiscID
COMMENT=	Perl interface for the MusicBrainz libdiscid library
LICENSE=	mit

DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

PERL5_PACKLIST=		auto/MusicBrainz/DiscID/.packlist

EXTRACT_USING=	bsdtar
USE_TOOLS+=	pkg-config

.include "../../audio/libdiscid/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
