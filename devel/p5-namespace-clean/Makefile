# $NetBSD: Makefile,v 1.3 2008/11/17 22:51:21 he Exp $

DISTNAME=	namespace-clean-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=namespace/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/namespace-clean/
COMMENT=	Perl module to keep imports and functions out of your namespace

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-B-Hooks-EndOfScope>0:../../devel/p5-B-Hooks-EndOfScope

PERL5_PACKLIST=		auto/namespace/clean/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
