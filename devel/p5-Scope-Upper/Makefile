# $NetBSD: Makefile,v 1.6 2011/08/14 12:26:35 obache Exp $

DISTNAME=	Scope-Upper-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Scope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Scope-Upper/
COMMENT=	Perl5 module to act on upper scopes
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Scope/Upper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
