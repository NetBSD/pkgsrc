# $NetBSD: Makefile,v 1.15 2008/08/11 14:59:49 he Exp $

DISTNAME=	Pod-Simple-3.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Simple/
COMMENT=	Simple framework for parsing Pod

DEPENDS+=	p5-Pod-Escapes>=1.04:../../textproc/p5-Pod-Escapes

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Pod/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
