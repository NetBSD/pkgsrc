# $NetBSD: Makefile,v 1.4 2002/10/20 17:46:01 seb Exp $

DISTNAME=	tagged-0.30
PKGNAME=	p5-MP3-Tag-0.30
SVR4_PKGNAME=	p5mp3
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MP3/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://tagged.sourceforge.net
COMMENT=	this is a perl module to read/write tags of mp3-files

DEPENDS=        p5-Compress-Zlib-1.*:../../devel/p5-Compress-Zlib

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MP3/Tag/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
