# $NetBSD: Makefile,v 1.7 2012/10/31 11:19:03 asau Exp $
#

DISTNAME=	Test-CheckManifest-1.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
