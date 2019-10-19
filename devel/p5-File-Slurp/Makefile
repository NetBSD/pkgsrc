# $NetBSD: Makefile,v 1.27 2019/10/19 12:49:53 mef Exp $

DISTNAME=	File-Slurp-9999.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/File-Slurp
COMMENT=	Read/write/append files quickly
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Slurp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
