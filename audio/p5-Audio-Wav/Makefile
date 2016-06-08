# $NetBSD: Makefile,v 1.26 2016/06/08 19:22:15 wiz Exp $

DISTNAME=	Audio-Wav-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Audio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Audio-Wav/
COMMENT=	Perl modules for reading & writing Microsoft WAV files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Audio/Wav/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
