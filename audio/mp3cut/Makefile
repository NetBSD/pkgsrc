# $NetBSD: Makefile,v 1.19 2022/06/28 11:30:55 wiz Exp $

DISTNAME=	mp3cut-1.13
PKGREVISION=	12
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JV/JV/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/JV/mp3cut-1.13
COMMENT=	Tools to concatenate and split MP3 files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-CDDB-File>=1.05:../../audio/p5-CDDB-File
DEPENDS+=	p5-MPEG-Audio-Frame>=0.09:../../audio/p5-MPEG-Audio-Frame

USE_TOOLS+=	perl:run

PERL5_PACKLIST=	auto/mp3cut/.packlist

INSTALLATION_DIRS+=	bin

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
