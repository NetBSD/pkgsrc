# $NetBSD: Makefile,v 1.9 2005/04/11 21:44:56 tv Exp $

DISTNAME=	MP3-Info-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MP3/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?module=MP3::Info
COMMENT=	Manipulate / fetch info from MP3 audio files

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MP3/Info/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
