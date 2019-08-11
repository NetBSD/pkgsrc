# $NetBSD: Makefile,v 1.21 2019/08/11 13:18:27 wiz Exp $

DISTNAME=	DBIx-Class-EncodedColumn-0.00015
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBIx-Class-EncodedColumn
COMMENT=	DBIx::Class component to automatically encode columns
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DBIx-Class>=0.06002:../../databases/p5-DBIx-Class
DEPENDS+=	p5-Sub-Name>=0.04:../../devel/p5-Sub-Name

# Feature: Digest::MD5 support
#DEPENDS+=	{perl>=5.7.3,p5-Digest-[0-9]*}:../../security/p5-Digest
#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5

# Feature: Digest::SHA support
#DEPENDS+=	{perl>=5.10.0,p5-Digest-SHA-[0-9]*}:../../security/p5-Digest-SHA

# Feature: Blowfish support
DEPENDS+=	p5-Crypt-Eksblowfish-[0-9]*:../../security/p5-Crypt-Eksblowfish

#Feature: Crypt::OpenPGP (gpg) Support
DEPENDS+=	p5-Crypt-OpenPGP-[0-9]*:../../security/p5-Crypt-OpenPGP
DEPENDS+=	p5-Crypt-CAST5_PP-[0-9]*:../../security/p5-Crypt-CAST5_PP

BUILD_DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
BUILD_DEPENDS+=	p5-Dir-Self-[0-9]*:../../devel/p5-Dir-Self
BUILD_DEPENDS+=	p5-SQL-Translator>=0.11002:../../databases/p5-SQL-Translator
BUILD_DEPENDS+=	p5-Module-Install-ReadmeFromPod-[0-9]*:../../devel/p5-Module-Install-ReadmeFromPod

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/DBIx/Class/EncodedColumn/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
