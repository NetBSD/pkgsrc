# $NetBSD: Makefile,v 1.38 2018/07/20 13:04:03 wen Exp $

DISTNAME=	File-Temp-0.2308
PKGNAME=	p5-${DISTNAME:S/08/.08/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Temp/
COMMENT=	Provides functions for generating temporary files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Temp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
