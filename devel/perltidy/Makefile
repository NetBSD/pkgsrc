# $NetBSD: Makefile,v 1.3 2013/01/05 13:32:17 darcy Exp $

DISTNAME=	Perl-Tidy-20121207
PKGNAME=	perltidy-20121207
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SH/SHANCOCK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Perl-Tidy/
HOMEPAGE=	http://perltidy.sourceforge.net/
COMMENT=	Indents and reformats Perl scripts to make them easier to read
LICENSE=    gnu-gpl-v2

USE_TOOLS+= perl

PERL5_PACKLIST=     auto/Perl/Tidy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
