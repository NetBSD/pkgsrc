# $NetBSD: Makefile,v 1.13 2018/08/22 09:42:55 wiz Exp $

DISTNAME=	mp3cut-1.13
PKGREVISION=	8
CATEGORIES=	audio perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/J/JV/JV/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~jv/mp3cut/
COMMENT=	Tools to concatenate and split MP3 files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-CDDB-File>=1.05:../../audio/p5-CDDB-File
DEPENDS+=	p5-MPEG-Audio-Frame>=0.09:../../audio/p5-MPEG-Audio-Frame

USE_TOOLS+=	perl:run

PERL5_PACKLIST=	auto/mp3cut/.packlist

INSTALLATION_DIRS+=	bin

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
