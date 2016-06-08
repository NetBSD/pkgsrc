# $NetBSD: Makefile,v 1.4 2016/06/08 19:24:24 wiz Exp $
#

DISTNAME=	File-Inplace-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~chipt/File-Inplace/
COMMENT=	Perl module for in-place editing of files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/File/Inplace/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
