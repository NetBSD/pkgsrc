# $NetBSD: Makefile,v 1.39 2016/02/04 12:02:31 mef Exp $

DISTNAME=	Pod-Simple-3.32
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Simple/
COMMENT=	Simple framework for parsing Pod
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.9.3,p5-Pod-Escapes>=1.04}:../../textproc/p5-Pod-Escapes

PERL5_PACKLIST=		auto/Pod/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
