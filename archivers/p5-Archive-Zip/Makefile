# $NetBSD: Makefile,v 1.71 2023/07/06 09:38:08 wiz Exp $

DISTNAME=	Archive-Zip-1.68
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Archive-Zip
COMMENT=	Perl5 module interface to manipulate zip files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-SUPER-[0-9]*:../../devel/p5-SUPER
TEST_DEPENDS+=	p5-Test-MockModule-[0-9]*:../../devel/p5-Test-MockModule

# TEST_DEPENDS? Perhaps run dependency? NetBSD's unzip is not good enough
TOOL_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Archive/Zip/.packlist

post-extract:
	rm -rf ${WRKSRC}/PaxHeader ${WRKSRC}/*/PaxHeader ${WRKSRC}/*/*/PaxHeader

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
