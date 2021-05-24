# $NetBSD: Makefile,v 1.31 2021/05/24 19:50:43 wiz Exp $

DISTNAME=	File-Slurp-9999.32
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/File-Slurp
COMMENT=	Read/write/append files quickly
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Slurp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
