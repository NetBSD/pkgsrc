# $NetBSD: Makefile,v 1.3 2003/06/02 01:21:35 jschauma Exp $
#

DISTNAME=	Audio-Wav-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Audio/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://search.cpan.org/dist/Audio-Wav/
COMMENT=	perl modules for reading & writing Microsoft WAV files

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Audio/Wav/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
