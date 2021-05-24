# $NetBSD: Makefile,v 1.15 2021/05/24 19:51:57 wiz Exp $
#

DISTNAME=	constant-def-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MO/MONS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/release/MONS/constant-def-0.01/lib/constant/def.pm
COMMENT=	Perl pragma to declare previously undeclared constants
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.13.11,p5-Test-Simple>=0.98}:../../devel/p5-Test-Simple
DEPENDS+=	p5-ex-lib>=0.03:../../devel/p5-ex-lib

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
