# $NetBSD: Makefile,v 1.22 2019/08/11 13:19:35 wiz Exp $

DISTNAME=	IMDB-Film-0.53
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/ST/STEPANOV/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IMDB-Film
COMMENT=	Perl module for accessing IMDB (Internet Movie Database)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Cache-Cache-[0-9]*:../../devel/p5-Cache-Cache
DEPENDS+=	p5-HTML-TokeParser-Simple>=2.28:../../www/p5-HTML-TokeParser-Simple
DEPENDS+=	p5-libwww>=1.41:../../www/p5-libwww
DEPENDS+=	p5-Text-Unidecode-[0-9]*:../../textproc/p5-Text-Unidecode

PERL5_PACKLIST=		auto/IMDB/Film/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
