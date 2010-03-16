# $NetBSD: Makefile,v 1.14 2010/03/16 10:47:57 sno Exp $
#

DISTNAME=	JSON-XS-2.28
PKGNAME=	p5-${DISTNAME}0
CATEGORIES=	textproc perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN:=JSON/}
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN:=../../authors/id/M/ML/MLEHMANN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JSON-XS/
COMMENT=	JSON serialising/deserialising, done correctly and fast
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/JSON/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
