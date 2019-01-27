# $NetBSD: Makefile,v 1.18 2019/01/27 13:16:26 wen Exp $

DISTNAME=	Devel-TraceUse-2.096
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-TraceUse/
COMMENT=	Show the modules your Perl program loads, recursively
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Devel/TraceUse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
