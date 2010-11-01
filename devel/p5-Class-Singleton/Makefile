# $NetBSD: Makefile,v 1.10 2010/11/01 00:08:10 wiz Exp $

DISTNAME=	Class-Singleton-1.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Singleton/
COMMENT=	Perl module to implement Singleton classes
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Class/Singleton/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
