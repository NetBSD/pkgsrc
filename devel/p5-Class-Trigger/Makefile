# $NetBSD: Makefile,v 1.11 2009/10/12 12:07:56 rhaen Exp $
#

DISTNAME=	Class-Trigger-0.14
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ctr
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIYAGAWA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Trigger/
COMMENT=	Mixin to add/call inheritable triggers
LICENSE=  ${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-IO-stringy>=0.02:../../devel/p5-IO-stringy

PERL5_PACKLIST=	auto/Class/Trigger/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
