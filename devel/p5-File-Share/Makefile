# $NetBSD: Makefile,v 1.11 2022/07/31 08:22:42 wen Exp $

DISTNAME=	File-Share-0.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Share
COMMENT=	Extend File::ShareDir to Local Libraries
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/File/Share/.packlist

DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=	p5-Readonly-[0-9]*:../../devel/p5-Readonly

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
