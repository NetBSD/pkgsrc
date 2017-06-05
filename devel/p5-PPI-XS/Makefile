# $NetBSD: Makefile,v 1.14 2017/06/05 14:23:25 ryoon Exp $
#

DISTNAME=	PPI-XS-0.904
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PPI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PPI-XS/
COMMENT=	Perl 5 XS acceleration for the PPI perl parser
LICENSE=	gnu-gpl-v2 # OR artistic

# Before update this package, please check $PM_COMPATIBLE in lib/PPI/XS.pm.
# If it is greater than version of devel/p5-PPI, p5-PPI should be updated.
DEPENDS+=	p5-PPI>=1.203:../../devel/p5-PPI

BUILD_DEPENDS+=	p5-ExtUtils-AutoInstall>=0.63:../../devel/p5-ExtUtils-AutoInstall

USE_LANGUAGES=c
PERL5_PACKLIST=	auto/PPI/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
