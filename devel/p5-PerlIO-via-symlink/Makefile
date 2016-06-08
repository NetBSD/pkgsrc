# $NetBSD: Makefile,v 1.19 2016/06/08 19:23:26 wiz Exp $

DISTNAME=	PerlIO-via-symlink-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~clkao/PerlIO-via-symlink/
COMMENT=	PerlIO layers to create symlinks
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/PerlIO/via/symlink/.packlist
PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
