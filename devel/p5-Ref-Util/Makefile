# $NetBSD: Makefile,v 1.1 2016/08/07 09:05:50 wen Exp $

DISTNAME=	Ref-Util-0.020
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Ref/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Ref-Util/
COMMENT=	Utility functions for checking references
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Ref/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
