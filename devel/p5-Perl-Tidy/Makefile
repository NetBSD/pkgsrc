# $NetBSD: Makefile,v 1.22 2014/05/09 07:30:09 wen Exp $
#

DISTNAME=	Perl-Tidy-20140328
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pt
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Perl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perltidy.sourceforge.net/
#HOMEPAGE=	http://search.cpan.org/dist/Perl-Tidy/
COMMENT=	Parses and beautifies perl source
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Perl/Tidy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
