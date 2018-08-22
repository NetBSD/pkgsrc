# $NetBSD: Makefile,v 1.2 2018/08/22 09:43:39 wiz Exp $

DISTNAME=	CPAN-Common-Index-0.010
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CPAN-Common-Index/
COMMENT=	Library for searching CPAN modules, authors and distributions
LICENSE=	apache-2.0

DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
DEPENDS+=	p5-Test-FailWarnings-[0-9]*:../../devel/p5-Test-FailWarnings
DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
DEPENDS+=	p5-Tie-Handle-Offset-[0-9]*:../../textproc/p5-Tie-Handle-Offset

PERL5_PACKLIST=	auto/CPAN/Common/Index/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
