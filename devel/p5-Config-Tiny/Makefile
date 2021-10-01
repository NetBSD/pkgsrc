# $NetBSD: Makefile,v 1.32 2021/10/01 23:58:27 wen Exp $

DISTNAME=	Config-Tiny-2.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Config-Tiny
COMMENT=	Read/Write .ini style files with as little code as possible
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Config/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
