# $NetBSD: Makefile,v 1.23 2019/08/11 13:19:35 wiz Exp $

DISTNAME=	IO-AIO-4.72
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-AIO
COMMENT=	Perl 5 module implementing asynchronous input/output
LICENSE=	${PERL5_LICENSE}

# Note: libeio is bundle with the distribution tarball.
# Its configure script is run via  Makefile.PL
# with all perl configuration settings, id est
# the Config module, set in its environment

# build time requirment
BUILD_DEPENDS+=	p5-Canary-Stability-[0-9]*:../../devel/p5-Canary-Stability

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/IO/AIO/.packlist

DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
