# $NetBSD: Makefile,v 1.5 2010/09/02 20:47:05 sno Exp $
#

DISTNAME=	Contextual-Return-0.003001
PKGNAME=	p5-${DISTNAME:S/003001/003.001/}
#PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DC/DCONWAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Contextual-Return/
COMMENT=	Perl 5 module to create context-senstive return values
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{perl>=5.10.0,p5-version-[0-9]*}:../../devel/p5-version
DEPENDS+=	p5-Want-[0-9]*:../../devel/p5-Want

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Contextual/Return/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
