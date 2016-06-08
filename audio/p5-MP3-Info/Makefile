# $NetBSD: Makefile,v 1.26 2016/06/08 19:22:15 wiz Exp $

DISTNAME=	MP3-Info-1.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MP3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MP3-Info/
COMMENT=	Manipulate/fetch info from MP3 audio files
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/MP3/Info/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
