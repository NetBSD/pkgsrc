# $NetBSD: Makefile,v 1.1.1.1 2002/08/26 01:46:41 grant Exp $
#

DISTNAME=	Audio-Wav-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Audio/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://search.cpan.org/dist/Audio-Wav/
COMMENT=	perl modules for reading & writing Microsoft WAV files

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Audio/Wav/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
