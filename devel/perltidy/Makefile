# $NetBSD: Makefile,v 1.1.1.1 2007/04/30 15:16:12 abs Exp $
#

DISTNAME=	Perl-Tidy-20070424
PKGNAME=	${DISTNAME:S/Perl-Tidy/perltidy/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=perltidy/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://perltidy.sourceforge.net/
COMMENT=	Indents and reformats Perl scripts to make them easier to read

PERL5_PACKLIST= auto/Perl/Tidy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
