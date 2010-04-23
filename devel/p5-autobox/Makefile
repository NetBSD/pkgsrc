# $NetBSD: Makefile,v 1.3 2010/04/23 03:56:14 seb Exp $
#

DISTNAME=	autobox-2.70
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=autobox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/autobox/
COMMENT=	Perl 5 module to add methods on native types
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/autobox/.packlist

DEPENDS+=	p5-Scope-Guard>=0.03:../../devel/p5-Scope-Guard

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
