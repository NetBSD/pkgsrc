# $NetBSD: Makefile,v 1.13 2023/07/06 09:40:58 wiz Exp $

DISTNAME=	Business-ISSN-1.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/release/BDFOY/Business-ISSN-0.91/lib/ISSN.pm
COMMENT=	Perl5 extention for International Standard Serial Numbers
LICENSE=	artistic-2.0

PERL5_PACKLIST=	auto/Business/ISSN/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
