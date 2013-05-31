# $NetBSD: Makefile,v 1.7 2013/05/31 12:41:24 wiz Exp $
#

DISTNAME=	Roman-1.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
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
