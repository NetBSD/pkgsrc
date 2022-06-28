# $NetBSD: Makefile,v 1.42 2022/06/28 11:32:22 wiz Exp $

DISTNAME=	ExtUtils-F77-1.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/ExtUtils::F77
COMMENT=	Perl module for determining how to link Fortran and C
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which

USE_LANGUAGES=		fortran77
PERL5_PACKLIST=		auto/ExtUtils/F77/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
