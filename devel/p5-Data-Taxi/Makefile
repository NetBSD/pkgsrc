# $NetBSD: Makefile,v 1.6 2011/08/12 06:38:28 adam Exp $

DISTNAME=	Data-Taxi-0.96
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Taxi/
COMMENT=	Perl 5 module providing taint-aware, XML-ish data serialization
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Taxi/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
