# $NetBSD: Makefile,v 1.4 2010/08/21 16:34:35 seb Exp $
#

DISTNAME=	Test-Object-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
