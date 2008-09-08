# $NetBSD: Makefile,v 1.1.1.1 2008/09/08 21:55:25 seb Exp $
#

DISTNAME=	aliased-0.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/O/OV/OVID/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/aliased/
COMMENT=	Perl 5 module for use of shorter versions of class names

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/aliased/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
