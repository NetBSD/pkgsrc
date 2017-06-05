# $NetBSD: Makefile,v 1.16 2017/06/05 14:23:37 ryoon Exp $

DISTNAME=	Sub-Install-0.928
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sub-Install
COMMENT=	Install subroutines into packages easily
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Sub/Install/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
