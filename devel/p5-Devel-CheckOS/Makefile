# $NetBSD: Makefile,v 1.8 2013/08/15 15:12:36 wen Exp $

DISTNAME=	Devel-CheckOS-1.71
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-CheckOS/
COMMENT=	Perl extension to check what OS we are running on
LICENSE=	gnu-gpl-v2 OR artistic

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Data-Compare>=1.21:../../devel/p5-Data-Compare
DEPENDS+=	p5-File-Find-Rule>=0.28:../../devel/p5-File-Find-Rule
# 0.18 is in perl-5.10 core
DEPENDS+=	p5-File-Temp>=0.19:../../devel/p5-File-Temp

PERL5_PACKLIST=		auto/Devel/CheckOS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
