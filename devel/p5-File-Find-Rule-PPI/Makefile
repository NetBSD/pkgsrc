# $NetBSD: Makefile,v 1.15 2019/06/30 20:15:01 nia Exp $

DISTNAME=	File-Find-Rule-PPI-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Find-Rule-PPI
COMMENT=	Add support for PPI queries to File::Find::Rule
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-Find-Rule>=0.20:../../devel/p5-File-Find-Rule
DEPENDS+=	p5-PPI>=1.00:../../devel/p5-PPI
DEPENDS+=	p5-Params-Util>=0.10:../../devel/p5-Params-Util

PERL5_PACKLIST=		auto/File/Find/Rule/PPI/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
