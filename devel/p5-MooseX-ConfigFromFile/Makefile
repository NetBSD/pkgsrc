# $NetBSD: Makefile,v 1.4 2011/08/14 12:26:20 obache Exp $

DISTNAME=	MooseX-ConfigFromFile-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-ConfigFromFile/
COMMENT=	Abstract Moose role for setting attributes from a configfile
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=0.35:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types-Path-Class>=0.04:../../devel/p5-MooseX-Types-Path-Class

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/MooseX/ConfigFromFile/.packlist
PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
