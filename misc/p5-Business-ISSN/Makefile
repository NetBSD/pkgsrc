# $NetBSD: Makefile,v 1.3 2016/06/08 19:24:05 wiz Exp $
#

DISTNAME=	Business-ISSN-0.91
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~bdfoy/Business-ISSN-0.91/lib/ISSN.pm
COMMENT=	Perl5 extention for International Standard Serial Numbers
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Business/ISSN/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
