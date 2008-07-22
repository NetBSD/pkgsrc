# $NetBSD: Makefile,v 1.1.1.1 2008/07/22 22:57:04 he Exp $

DISTNAME=	namespace-clean-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=namespace/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/namespace-clean/
COMMENT=	Perl module to keep imports and functions out of your namespace

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Scope-Guard>=0.02:../../devel/p5-Scope-Guard

PERL5_PACKLIST=		auto/namespace/clean/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
