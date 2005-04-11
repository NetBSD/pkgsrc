# $NetBSD: Makefile,v 1.10 2005/04/11 21:44:56 tv Exp $

DISTNAME=	tagged-0.40
PKGNAME=	p5-MP3-Tag-0.40
SVR4_PKGNAME=	p5mp3
PKGREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MP3/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://tagged.sourceforge.net/
COMMENT=	This is a perl module to read/write tags of mp3-files

DEPENDS=        p5-Compress-Zlib-1.*:../../devel/p5-Compress-Zlib

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MP3/Tag/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
