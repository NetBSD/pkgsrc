# $NetBSD: Makefile,v 1.9 2013/09/05 06:30:44 wen Exp $
#

DISTNAME=	Test-CheckManifest-1.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-CheckManifest/
COMMENT=	Check if MANIFEST of perl module matches it's distro
LICENSE=	artistic-2.0

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/CheckManifest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
