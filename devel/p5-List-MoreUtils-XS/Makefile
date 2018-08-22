# $NetBSD: Makefile,v 1.7 2018/08/22 09:44:12 wiz Exp $

DISTNAME=	List-MoreUtils-XS-0.428
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/List-MoreUtils-XS/
COMMENT=	Provide compiled List::MoreUtils functions
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/List/MoreUtils/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
