# $NetBSD: Makefile,v 1.15 2019/08/11 13:21:50 wiz Exp $
#

DISTNAME=	Roman-1.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Roman/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Roman
COMMENT=	Conversion of numeric notation between Roman and Arabic
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Roman/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
