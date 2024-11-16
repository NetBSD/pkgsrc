# $NetBSD: Makefile,v 1.17 2024/11/16 12:04:28 wiz Exp $
#

DISTNAME=	LEOCHARRE-CLI2-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/L/LE/LEOCHARRE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/LEOCHARRE-CLI2
COMMENT=	Some quick help for writing cli scripts
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-Symdump>=2.07:../../devel/p5-Devel-Symdump
DEPENDS+=	p5-LEOCHARRE-Dir>=1.06:../../devel/p5-LEOCHARRE-Dir
DEPENDS+=	p5-Smart-Comments>=1:../../devel/p5-Smart-Comments
DEPENDS+=	p5-String-ShellQuote>=1.03:../../textproc/p5-String-ShellQuote
DEPENDS+=	p5-YAML>=0.66:../../textproc/p5-YAML

PERL5_PACKLIST=		auto/LEOCHARRE/CLI2/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
