# $NetBSD: Makefile,v 1.10 2025/07/04 08:46:11 wiz Exp $

DISTNAME=	MooX-Locale-Passthrough-0.001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RE/REHSACK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooX-Locale-Passthrough
COMMENT=	Provide API used in translator modules without translating
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/MooX/Locale/Passthrough/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
