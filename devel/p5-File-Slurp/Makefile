# $NetBSD: Makefile,v 1.20 2016/06/08 19:22:58 wiz Exp $

DISTNAME=	File-Slurp-9999.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/File-Slurp/
COMMENT=	Read/write/append files quickly
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Slurp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
