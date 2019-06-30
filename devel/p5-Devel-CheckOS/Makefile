# $NetBSD: Makefile,v 1.23 2019/06/30 20:14:53 nia Exp $

DISTNAME=	Devel-CheckOS-1.81
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-CheckOS
COMMENT=	Perl extension to check what OS we are running on
LICENSE=	gnu-gpl-v2 OR artistic

DEPENDS+=	p5-Data-Compare>=1.21:../../devel/p5-Data-Compare
DEPENDS+=	p5-File-Find-Rule>=0.28:../../devel/p5-File-Find-Rule
#DEPENDS+=	{perl>=5.10.1,p5-File-Temp>=0.19}:../../devel/p5-File-Temp

PERL5_PACKLIST=		auto/Devel/CheckOS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
