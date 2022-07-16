# $NetBSD: Makefile,v 1.31 2022/07/16 00:35:07 wen Exp $

DISTNAME=	Devel-CheckOS-1.93
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-CheckOS
COMMENT=	Perl extension to check what OS we are running on
LICENSE=	gnu-gpl-v2 OR artistic

DEPENDS+=	p5-File-Find-Rule>=0.28:../../devel/p5-File-Find-Rule

TEST_DEPENDS+=	p5-Test-Warnings>=0:../../devel/p5-Test-Warnings

PERL5_PACKLIST=		auto/Devel/CheckOS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
