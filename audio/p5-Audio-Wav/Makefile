# $NetBSD: Makefile,v 1.33 2022/06/28 11:30:56 wiz Exp $

DISTNAME=	Audio-Wav-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Audio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Audio-Wav
COMMENT=	Perl modules for reading & writing Microsoft WAV files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Audio/Wav/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
