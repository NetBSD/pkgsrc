# $NetBSD: Makefile,v 1.4 2025/10/04 01:03:05 wen Exp $

DISTNAME=		File-Scan-ClamAV-1.96
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ES/ESAYM/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/dist/File-Scan-ClamAV
COMMENT=		Library for sending commands to a local clamd
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		clamav-[0-9]*:../../security/clamav

PERL5_PACKLIST=		auto/File/Scan/ClamAV/.packlist
USE_LANGUAGES=		# none

MAKE_ENV+=		CLAMD_PATH=${PREFIX:Q}/sbin

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
