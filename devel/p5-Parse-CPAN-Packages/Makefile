# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:28 obache Exp $
#

DISTNAME=	Parse-CPAN-Packages-2.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Parse-CPAN-Packages/
COMMENT=	Perl 5 module to parse 02packages.details.txt.gz
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Parse/CPAN/Packages/.packlist

DEPENDS+=	p5-CPAN-DistnameInfo-[0-9]*:../../devel/p5-CPAN-DistnameInfo
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
