# $NetBSD: Makefile,v 1.1 2017/07/10 03:06:45 wen Exp $

DISTNAME=	MooX-Locale-Passthrough-0.001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RE/REHSACK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rehsack/MooX-Locale-Passthrough/
COMMENT=	Provide API used in translator modules without translating
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/MooX/Locale/Passthrough/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
