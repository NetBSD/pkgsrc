# $NetBSD: Makefile,v 1.8 2014/05/29 23:36:55 wiz Exp $
#

DISTNAME=	Roman-1.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Roman/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Roman/
COMMENT=	Conversion of numeric notation between Roman and Arabic

PERL5_PACKLIST=	auto/Roman/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
