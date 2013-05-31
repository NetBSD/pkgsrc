# $NetBSD: Makefile,v 1.8 2013/05/31 12:40:05 wiz Exp $

DISTNAME=	CPAN-Checksums-2.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CPAN-Checksums/
COMMENT=	Write a CHECKSUMS file for a directory as on CPAN
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Compress-Bzip2-[0-9]*:../../archivers/p5-Compress-Bzip2
DEPENDS+=	p5-Data-Compare-[0-9]*:../../devel/p5-Data-Compare

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CPAN/Checksums/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
