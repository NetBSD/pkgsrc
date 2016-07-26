# $NetBSD: Makefile,v 1.3 2016/07/26 13:46:39 mef Exp $

DISTNAME=	File-Share-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Share/
COMMENT=	Extend File::ShareDir to Local Libraries
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/File/Share/.packlist

# for make test
BUILD_DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
