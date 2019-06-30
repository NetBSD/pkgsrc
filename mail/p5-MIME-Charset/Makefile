# $NetBSD: Makefile,v 1.20 2019/06/30 20:16:15 nia Exp $

DISTNAME=	MIME-Charset-1.012.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MIME-Charset
COMMENT=	Perl5 module containing charset Informations for MIME
LICENSE=	${PERL5_LICENSE}

# extra requirement for:
# extended mappings by Japanese codepages
# Encode::EUCJPASCII >= 0.02
# additional mappings for JIS X 0213:2000
# Encode::JIS2K >= 0.02
# additional mappings for Chinese standards
# Encode::HanExtra >= 0.20

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MIME/Charset/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
