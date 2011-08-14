# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:30 obache Exp $

DISTNAME=	Path-Dispatcher-Declarative-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SA/SARTAK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Path-Dispatcher-Declarative/
COMMENT=	Perl 5 module providing a sugary dispatcher
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Path/Dispatcher/Declarative/.packlist

DEPENDS+=	p5-Any-Moose-[0-9]*:../../devel/p5-Any-Moose
DEPENDS+=	p5-Path-Dispatcher>=0.15:../../devel/p5-Path-Dispatcher
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
