# $NetBSD: Makefile,v 1.1 2012/07/05 15:35:34 sno Exp $

DISTNAME=	Sub-Exporter-ForMethods-0.100050
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Exporter-ForMethods/
COMMENT=	Perl 5 helper routines for using Sub::Exporter to build methods
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter>=0.978:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Sub/Exporter/ForMethods/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
