# $NetBSD: Makefile,v 1.20 2017/06/05 14:22:56 ryoon Exp $

DISTNAME=	ExtUtils-AutoInstall-0.64
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-AutoInstall/
COMMENT=	Lets Makefile.PL automatically install dependencies
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sort-Versions>=1.2:../../devel/p5-Sort-Versions

MAKE_ENV+=		PERL_EXTUTILS_AUTOINSTALL=--skip
PERL5_PACKLIST=		auto/ExtUtils/AutoInstall/.packlist

# getting infinite loop
TEST_TARGET?=	# empty = means make test fails

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
