# $NetBSD: Makefile,v 1.4 2010/08/21 16:33:21 seb Exp $
#

DISTNAME=	Class-InsideOut-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-InsideOut/
COMMENT=	Perl 5 safe and simple inside-out object construction kit
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Class/InsideOut/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
