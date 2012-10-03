# $NetBSD: Makefile,v 1.7 2012/10/03 21:57:52 wiz Exp $

DISTNAME=	Kwalify-1.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/SR/SREZIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Kwalify/
COMMENT=	Perl implementation of Kwalify parser, validator and data binding tool
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Kwalify/.packlist

# For test really
BUILD_DEPENDS+=	p5-YAML-Syck-[0-9]*:../../textproc/p5-YAML-Syck

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
