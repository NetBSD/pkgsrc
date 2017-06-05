# $NetBSD: Makefile,v 1.23 2017/06/05 14:22:20 ryoon Exp $

DISTNAME=	Convert-BinHex-1.125
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?query=convert+binhex
COMMENT=	Read and write Macintosh BinHex streams
LICENSE=	${PERL5_LICENSE}

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Most-[0-9]*:../../devel/p5-Test-Most
BUILD_DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
BUILD_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

PERL5_PACKLIST=		auto/Convert/BinHex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
