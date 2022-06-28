# $NetBSD: Makefile,v 1.14 2022/06/28 11:32:27 wiz Exp $

DISTNAME=	File-ShareDir-ProjectDistDir-1.000009
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-ShareDir-ProjectDistDir
COMMENT=	Perl extension for set-and-forget using a directory in projects root
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-ShareDir>=0:../../devel/p5-File-ShareDir
DEPENDS+=	p5-Path-Class>=0:../../devel/p5-Path-Class
DEPENDS+=	p5-Path-FindDev>=0:../../devel/p5-Path-FindDev
DEPENDS+=	p5-Path-IsDev>=0:../../devel/p5-Path-IsDev
DEPENDS+=	p5-Path-Tiny>=0:../../filesystems/p5-Path-Tiny
DEPENDS+=	p5-Sub-Exporter>=0:../../devel/p5-Sub-Exporter

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/File/ShareDir/ProjectDistDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
