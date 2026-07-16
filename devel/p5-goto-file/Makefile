# $NetBSD: Makefile,v 1.2 2026/07/16 19:03:46 wiz Exp $

DISTNAME=		goto-file-0.005
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/goto-file
COMMENT=		Stop parsing the current file and move on to a different one
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/goto/file/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
