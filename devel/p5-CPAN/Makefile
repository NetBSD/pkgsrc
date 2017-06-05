# $NetBSD: Makefile,v 1.19 2017/06/05 14:22:38 ryoon Exp $

DISTNAME=	CPAN-2.16
PKGNAME=	p5-${DISTNAME}00
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CPAN
COMMENT=	Perl module to query, download and build perl modules from CPAN sites
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which
DEPENDS+=	p5-Module-Signature-[0-9]*:../../security/p5-Module-Signature
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
# DEPENDS+=	{perl>=5.008009,p5-Test-Harness>=2.62}:../../devel/p5-Test-Harness
DEPENDS+=	p5-Text-Glob-[0-9]*:../../textproc/p5-Text-Glob
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-YAML-Syck-[0-9]*:../../textproc/p5-YAML-Syck
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_LANGUAGES+=		c
MAKE_PARAMS+=		verbose
PERL5_PACKLIST=		auto/CPAN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
