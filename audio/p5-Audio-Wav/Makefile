# $NetBSD: Makefile,v 1.18 2011/08/06 12:49:26 adam Exp $

DISTNAME=	Audio-Wav-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
