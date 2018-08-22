# $NetBSD: Makefile,v 1.6 2018/08/22 09:45:45 wiz Exp $
#

DISTNAME=	Business-ISSN-1.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~bdfoy/Business-ISSN-0.91/lib/ISSN.pm
COMMENT=	Perl5 extention for International Standard Serial Numbers
LICENSE=	artistic-2.0

PERL5_PACKLIST=	auto/Business/ISSN/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
