# $NetBSD: Makefile,v 1.8 2005/04/11 21:44:55 tv Exp $
#

DISTNAME=	Audio-Wav-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Audio/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Audio-Wav/
COMMENT=	Perl modules for reading & writing Microsoft WAV files

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Audio/Wav/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
