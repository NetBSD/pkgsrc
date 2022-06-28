# $NetBSD: Makefile,v 1.39 2022/06/28 11:30:56 wiz Exp $

DISTNAME=	MP3-Tag-1.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MP3/}
EXTRACT_SUFX=	.zip

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	https://metacpan.org/release/MP3-Tag
COMMENT=	This is a perl module to read/write tags of mp3-files
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.9.3,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress #Compress::Zlib>=0

PERL5_PACKLIST=		auto/MP3/Tag/.packlist

REPLACE_PERL+=	lib/Encode/transliterate_win1251.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
