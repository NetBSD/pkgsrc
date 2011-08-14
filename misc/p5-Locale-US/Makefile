# $NetBSD: Makefile,v 1.4 2011/08/14 13:45:16 obache Exp $
#

DISTNAME=	Locale-US-1.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Locale-US/
COMMENT=	Perl 5 module to maps US two-letter codes to states and vice versa

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Locale/US/.packlist
REPLACE_PERL=	kruft2codes.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
