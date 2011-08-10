# $NetBSD: Makefile,v 1.5 2011/08/10 04:16:07 adam Exp $

DISTNAME=	Class-InsideOut-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-InsideOut/
COMMENT=	Perl 5 safe and simple inside-out object construction kit
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Class/InsideOut/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
