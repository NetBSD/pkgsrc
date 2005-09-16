# $NetBSD: Makefile,v 1.9 2005/09/16 13:40:36 tv Exp $

DISTNAME=	Pod-Simple-3.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Simple/
COMMENT=	Simple framework for parsing Pod

DEPENDS+=	p5-Pod-Escapes-[0-9]*:../../textproc/p5-Pod-Escapes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Pod/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
