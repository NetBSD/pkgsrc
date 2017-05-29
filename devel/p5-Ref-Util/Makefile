# $NetBSD: Makefile,v 1.4 2017/05/29 11:05:08 wiz Exp $

DISTNAME=	Ref-Util-0.203
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Ref/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Ref-Util/
COMMENT=	Utility functions for checking references
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Ref-Util-XS-[0-9]*:../../devel/p5-Ref-Util-XS

PERL5_PACKLIST=		auto/Ref/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
