# $NetBSD: Makefile,v 1.1.1.1 2009/10/11 09:37:45 wiz Exp $

DISTNAME=	IMDB-Film-0.41
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/ST/STEPANOV/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IMDB-Film/
COMMENT=	Perl module for accessing IMDB (Internet Movie Database)

DEPENDS+=	p5-Cache-Cache-[0-9]*:../../devel/p5-Cache-Cache
DEPENDS+=	p5-HTML-TokeParser-Simple>=2.28:../../www/p5-HTML-TokeParser-Simple
DEPENDS+=	p5-libwww>=1.41:../../www/p5-libwww

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/IMDB/Film/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
