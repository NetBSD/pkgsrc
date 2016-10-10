# $NetBSD: Makefile,v 1.2 2016/10/10 12:37:14 mef Exp $

DISTNAME=	Ref-Util-0.101
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
