# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:02 veego Exp $

DISTNAME=	tagged-0.30
PKGNAME=	p5-MP3-Tag-0.30
SVR4_PKGNAME=	p5mp3
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MP3/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://tagged.sourceforge.net
COMMENT=	this is a perl module to read/write tags of mp3-files

DEPENDS=        p5-Compress-Zlib-1.*:../../devel/p5-Compress-Zlib

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/MP3/Tag/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
