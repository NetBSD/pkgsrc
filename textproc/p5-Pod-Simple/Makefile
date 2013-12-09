# $NetBSD: Makefile,v 1.32 2013/12/09 14:17:53 obache Exp $

DISTNAME=	Pod-Simple-3.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Simple/
COMMENT=	Simple framework for parsing Pod
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.9.3,p5-Pod-Escapes>=1.04}:../../textproc/p5-Pod-Escapes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Pod/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
