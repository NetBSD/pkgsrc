# $NetBSD: Makefile,v 1.5 2011/08/14 12:26:32 obache Exp $
#

DISTNAME=	Readonly-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Readonly/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Readonly/
COMMENT=	Perl 5 module for creating read-only scalars, arrays and hashes

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Readonly/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
