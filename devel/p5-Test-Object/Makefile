# $NetBSD: Makefile,v 1.6 2012/10/03 21:55:44 wiz Exp $
#

DISTNAME=	Test-Object-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Object/
COMMENT=	Perl 5 module to thoroughly test objects

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Object/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
