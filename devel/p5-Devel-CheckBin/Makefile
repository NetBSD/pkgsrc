# $NetBSD: Makefile,v 1.6 2017/06/05 14:22:51 ryoon Exp $

DISTNAME=	Devel-CheckBin-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-CheckBin/
COMMENT=	Perl extension to check that a command is available
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	p5-IO-CaptureOutput>=1.08.01:../../devel/p5-IO-CaptureOutput

PERL5_PACKLIST=		auto/Devel/CheckBin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
