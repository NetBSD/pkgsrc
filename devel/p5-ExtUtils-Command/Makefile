# $NetBSD: Makefile,v 1.1.1.1 2008/08/25 23:06:17 seb Exp $
#

DISTNAME=	ExtUtils-Command-1.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-Command/
COMMENT=	Perl 5 functions to replace common UNIX commands in Makefiles

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/ExtUtils/Command/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
