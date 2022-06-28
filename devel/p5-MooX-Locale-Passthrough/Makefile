# $NetBSD: Makefile,v 1.7 2022/06/28 11:32:49 wiz Exp $

DISTNAME=	MooX-Locale-Passthrough-0.001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RE/REHSACK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooX-Locale-Passthrough
COMMENT=	Provide API used in translator modules without translating
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/MooX/Locale/Passthrough/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
