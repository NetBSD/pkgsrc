# $NetBSD: Makefile,v 1.7 2011/08/14 12:26:29 obache Exp $

DISTNAME=	Path-Dispatcher-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SA/SARTAK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Path-Dispatcher/
COMMENT=	Perl 5 module providing flexible and extensible dispatch
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty

DEPENDS+=	p5-Any-Moose-[0-9]*:../../devel/p5-Any-Moose
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter

# For test target
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

PERL5_PACKLIST=	auto/Path/Dispatcher/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
