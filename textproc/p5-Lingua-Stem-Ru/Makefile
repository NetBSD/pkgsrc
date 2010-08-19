# $NetBSD: Makefile,v 1.1.1.1 2010/08/19 06:26:23 sno Exp $

DISTNAME=	Lingua-Stem-Ru-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lingua-Stem-Ru/
COMMENT=	Porter's stemming algorithm for Russian (KOI8-R only)
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Lingua/Stem/Ru/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
