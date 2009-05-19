# $NetBSD: Makefile,v 1.2 2009/05/19 23:16:24 sno Exp $

DISTNAME=	Scope-Upper-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Scope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Scope-Upper/
COMMENT=	Perl5 module to act on upper scopes
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Scope/Upper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
