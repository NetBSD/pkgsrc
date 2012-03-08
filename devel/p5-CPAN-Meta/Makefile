# $NetBSD: Makefile,v 1.3 2012/03/08 09:01:22 sno Exp $

DISTNAME=	CPAN-Meta-2.120630
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CPAN-Meta/
COMMENT=	Perl module for handling the distribution metadata for a CPAN dist
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

# this is the meta data backend which used YAML/JSON to read ...
DEPENDS+=	p5-Parse-CPAN-Meta>=1.4400:../../devel/p5-Parse-CPAN-Meta

PERL5_PACKLIST=		auto/CPAN/Meta/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
