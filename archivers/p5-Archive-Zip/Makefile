# $NetBSD: Makefile,v 1.64 2019/06/30 20:14:13 nia Exp $

DISTNAME=	Archive-Zip-1.64
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Archive-Zip
COMMENT=	Perl5 module interface to manipulate zip files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-SUPER-[0-9]*:../../devel/p5-SUPER
TEST_DEPENDS+=	p5-Test-MockModule-[0-9]*:../../devel/p5-Test-MockModule

# TEST_DEPENDS? Perhaps run dependency? NetBSD's unzip is not good enough
BUILD_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Archive/Zip/.packlist

post-extract:
	rm -rf ${WRKSRC}/PaxHeader ${WRKSRC}/*/PaxHeader ${WRKSRC}/*/*/PaxHeader

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
