# $NetBSD: Makefile,v 1.14 2024/05/27 08:02:04 wen Exp $

DISTNAME=	Business-ISSN-1.005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/Business-ISSN
COMMENT=	Perl5 extention for International Standard Serial Numbers
LICENSE=	artistic-2.0

PERL5_PACKLIST=	auto/Business/ISSN/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
