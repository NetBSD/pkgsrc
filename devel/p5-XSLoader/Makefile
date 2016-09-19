# $NetBSD: Makefile,v 1.13 2016/09/19 10:48:14 mef Exp $
#

DISTNAME=	XSLoader-0.24
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SA/SAPER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XSLoader/
COMMENT=	Dynamically load C libraries into Perl code
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/XSLoader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
