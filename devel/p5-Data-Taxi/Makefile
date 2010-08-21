# $NetBSD: Makefile,v 1.5 2010/08/21 16:33:31 seb Exp $
#

DISTNAME=	Data-Taxi-0.95
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Taxi/
COMMENT=	Perl 5 module providing taint-aware, XML-ish data serialization

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Data/Taxi/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
