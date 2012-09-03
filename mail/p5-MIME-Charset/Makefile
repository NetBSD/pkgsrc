# $NetBSD: Makefile,v 1.9 2012/09/03 11:16:22 sno Exp $
#

DISTNAME=	MIME-Charset-1.009.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MIME-Charset/
COMMENT=	Perl5 module containing charset Informations for MIME
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

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
