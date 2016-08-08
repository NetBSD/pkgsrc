# $NetBSD: Makefile,v 1.3 2016/08/08 05:21:32 mef Exp $

DISTNAME=	File-Slurper-0.009
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Slurper/
COMMENT=	Simple, sane and efficient module to slurp a file
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

PERL5_PACKLIST=		auto/File/Slurper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
