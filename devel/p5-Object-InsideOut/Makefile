# $NetBSD: Makefile,v 1.8 2009/05/19 23:12:38 sno Exp $
#

DISTNAME=	Object-InsideOut-3.55
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Object-InsideOut/
COMMENT=	Perl 5 module providing comprehensive inside-out object support
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Exception-Class>=1.29:../../devel/p5-Exception-Class
DEPENDS+=	p5-Want>=0.12:../../devel/p5-Want

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Object/InsideOut/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
