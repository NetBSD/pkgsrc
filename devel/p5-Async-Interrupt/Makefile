# $NetBSD: Makefile,v 1.3 2010/03/16 19:10:43 sno Exp $
#

DISTNAME=	Async-Interrupt-1.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/ML/MLEHMANN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Async-Interrupt/
COMMENT=	Allow C/XS libraries to interrupt perl asynchronously
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES+=	c
PERL5_PACKLIST=	auto/Async/Interrupt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
