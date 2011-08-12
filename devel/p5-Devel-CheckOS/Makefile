# $NetBSD: Makefile,v 1.4 2011/08/12 07:07:33 adam Exp $

DISTNAME=	Devel-CheckOS-1.64
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-CheckOS/
COMMENT=	Perl extension to check what OS we are running on
LICENSE=	gnu-gpl-v2 OR artistic

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Data-Compare>=1.21:../../devel/p5-Data-Compare
DEPENDS+=	p5-File-Find-Rule>=0.28:../../devel/p5-File-Find-Rule
# 0.18 is in perl-5.10 core
DEPENDS+=	p5-File-Temp>=0.19:../../devel/p5-File-Temp

PERL5_PACKLIST=		auto/Devel/CheckOS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
