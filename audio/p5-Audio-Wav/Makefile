# $NetBSD: Makefile,v 1.2 2002/10/20 17:46:01 seb Exp $
#

DISTNAME=	Audio-Wav-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Audio/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://search.cpan.org/dist/Audio-Wav/
COMMENT=	perl modules for reading & writing Microsoft WAV files

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Audio/Wav/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
