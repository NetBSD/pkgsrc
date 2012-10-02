# $NetBSD: Makefile,v 1.22 2012/10/02 23:48:03 asau Exp $

DISTNAME=	MP3-Tag-1.13
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mp3
PKGREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MP3/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://search.cpan.org/dist/MP3-Tag/
COMMENT=	This is a perl module to read/write tags of mp3-files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-Compress>=2.017:../../devel/p5-IO-Compress

PERL5_PACKLIST=		auto/MP3/Tag/.packlist

REPLACE_PERL+=	lib/Encode/transliterate_win1251.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
