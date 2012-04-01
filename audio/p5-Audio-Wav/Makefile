# $NetBSD: Makefile,v 1.19 2012/04/01 18:40:12 rhaen Exp $

DISTNAME=	Audio-Wav-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Audio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Audio-Wav/
COMMENT=	Perl modules for reading & writing Microsoft WAV files
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Audio/Wav/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
