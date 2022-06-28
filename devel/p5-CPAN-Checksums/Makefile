# $NetBSD: Makefile,v 1.24 2022/06/28 11:31:56 wiz Exp $

DISTNAME=	CPAN-Checksums-2.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CPAN-Checksums
COMMENT=	Write a CHECKSUMS file for a directory as on CPAN
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Compress-Bzip2-[0-9]*:../../archivers/p5-Compress-Bzip2
DEPENDS+=	p5-Data-Compare-[0-9]*:../../devel/p5-Data-Compare

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CPAN/Checksums/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
