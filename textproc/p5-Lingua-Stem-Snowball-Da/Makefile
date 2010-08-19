# $NetBSD: Makefile,v 1.1.1.1 2010/08/19 06:35:32 sno Exp $

DISTNAME=	Lingua-Stem-Snowball-Da-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lingua-Stem-Snowball-Da/
COMMENT=	Porters stemming algorithm for Denmark

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL+=	stemmer.pl

PERL5_PACKLIST=	auto/Lingua/Stem/Snowball/Da/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
