# $NetBSD: Makefile,v 1.34 2022/06/28 11:32:08 wiz Exp $

DISTNAME=	Config-Tiny-2.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
