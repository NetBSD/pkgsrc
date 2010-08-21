# $NetBSD: Makefile,v 1.4 2010/08/21 16:33:28 seb Exp $
#

DISTNAME=	Contextual-Return-v0.2.1
PKGNAME=	p5-Contextual-Return-0.2.1
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DC/DCONWAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Contextual-Return/
COMMENT=	Perl 5 module to create context-senstive return values

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version
DEPENDS+=	p5-Want-[0-9]*:../../devel/p5-Want

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Contextual/Return/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
