# $NetBSD: Makefile,v 1.1.1.1 2009/12/05 00:29:51 seb Exp $
#

DISTNAME=	Devel-Dumpvar-1.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Dumpvar/
COMMENT=	Perl 5 module providing a pure-OO reimplementation of dumpvar.pl

USE_LANGUAGES=		# empty
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Devel/Dumpvar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
