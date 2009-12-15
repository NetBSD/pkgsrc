# $NetBSD: Makefile,v 1.19 2009/12/15 13:33:55 wiz Exp $

DISTNAME=	Pod-Simple-3.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Simple/
COMMENT=	Simple framework for parsing Pod
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Pod-Escapes>=1.04:../../textproc/p5-Pod-Escapes

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Pod/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
