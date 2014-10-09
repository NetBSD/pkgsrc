# $NetBSD: Makefile,v 1.7 2014/10/09 14:06:18 wiz Exp $

DISTNAME=	File-Slurp-Unicode-0.7.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Slurp-Unicode/
COMMENT=	Read/write/append files quickly
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/File/Slurp/Unicode/.packlist

DEPENDS+=		p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
