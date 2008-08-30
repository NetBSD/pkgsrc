# $NetBSD: Makefile,v 1.1.1.1 2008/08/30 21:09:55 seb Exp $

DISTNAME=	Kwalify-1.19
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/SR/SREZIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Kwalify/
COMMENT=	Perl implementation of Kwalify parser, validator and data binding tool

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Kwalify/.packlist

# For test really
BUILD_DEPENDS+=	p5-YAML-Syck-[0-9]*:../../textproc/p5-YAML-Syck

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
