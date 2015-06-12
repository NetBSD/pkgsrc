# $NetBSD: Makefile,v 1.36 2015/06/12 10:51:26 wiz Exp $

DISTNAME=	Pod-Simple-3.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Simple/
COMMENT=	Simple framework for parsing Pod
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.9.3,p5-Pod-Escapes>=1.04}:../../textproc/p5-Pod-Escapes

PERL5_PACKLIST=		auto/Pod/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
