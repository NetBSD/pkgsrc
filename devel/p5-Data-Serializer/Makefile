# $NetBSD: Makefile,v 1.23 2022/06/28 11:32:12 wiz Exp $

DISTNAME=	Data-Serializer-0.65
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Serializer
COMMENT=	Perl 5 module to serialize data structures
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Serializer/.packlist

#DEPENDS+=	{perl>=5.10,p5-Digest-SHA-[0-9]*}:../../security/p5-Digest-SHA

# Commented dependencies are recommended packages/modules for use with
# this package/module
#DEPENDS+=	p5-Compress-PPMd-[0-9]*:../../devel/p5-Compress-PPMd
#DEPENDS+=	p5-Config-General-[0-9]*:../../devel/p5-Config-General
#DEPENDS+=	p5-Crypt-Blowfish-[0-9]*:../../security/p5-Crypt-Blowfish
#DEPENDS+=	p5-Crypt-CBC-[0-9]*:../../security/p5-Crypt-CBC
#DEPENDS+=	p5-FreezeThaw-[0-9]*:../../devel/p5-FreezeThaw
#DEPENDS+=	p5-IO-Compress-[0-9]*:../../devel/p5-Compress-Zlib
#DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS
#DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
#DEPENDS+=	p5-MIME-Base64-[0-9]*:converters/p5-MIME-Base64
#DEPENDS+=	p5-PHP-Serialization-[0-9]*:../../devel/p5-PHP-Serialization
#DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
#DEPENDS+=	p5-YAML-Syck-[0-9]*:../../textproc/p5-YAML-Syck
#DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML

TEST_DEPENDS+=	p5-XML-Dumper-[0-9]*:../../textproc/p5-XML-Dumper
TEST_DEPENDS+=	p5-PHP-Serialization-[0-9]*:../../devel/p5-PHP-Serialization
TEST_DEPENDS+=	p5-Data-Taxi-[0-9]*:../../devel/p5-Data-Taxi
TEST_DEPENDS+=	p5-Data-Denter-[0-9]*:../../devel/p5-Data-Denter
TEST_DEPENDS+=	p5-Test-Kwalitee-[0-9]*:../../devel/p5-Test-Kwalitee

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
