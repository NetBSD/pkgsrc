# $NetBSD: Makefile,v 1.42 2019/08/11 13:18:31 wiz Exp $
#

DISTNAME=		MLDBM-2.05
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MLDBM/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/MLDBM
COMMENT=		Store multi-level Perl hash structure in single level tied hash
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MLDBM/.packlist
PERL5_MODULE_TYPE=	Module::Build

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
