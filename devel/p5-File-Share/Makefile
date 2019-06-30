# $NetBSD: Makefile,v 1.6 2019/06/30 20:15:03 nia Exp $

DISTNAME=	File-Share-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Share
COMMENT=	Extend File::ShareDir to Local Libraries
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/File/Share/.packlist

# for make test
BUILD_DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
