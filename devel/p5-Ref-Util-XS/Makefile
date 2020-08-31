# $NetBSD: Makefile,v 1.7 2020/08/31 18:08:46 wiz Exp $

DISTNAME=	Ref-Util-XS-0.117
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Ref/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Ref-Util-XS
COMMENT=	XS implementation for Ref::Util
LICENSE=	mit

PERL5_PACKLIST=		auto/Ref/Util/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
