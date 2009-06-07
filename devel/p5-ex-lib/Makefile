# $NetBSD: Makefile,v 1.3 2009/06/07 12:36:17 seb Exp $
#

DISTNAME=	ex-lib-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ex-lib/
COMMENT=	Perl 5 module to add in @INC absolute paths from relative ones

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/ex/lib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
