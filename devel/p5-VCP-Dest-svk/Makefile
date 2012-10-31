# $NetBSD: Makefile,v 1.9 2012/10/31 11:19:16 asau Exp $

DISTNAME=	VCP-Dest-svk-0.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/C/CL/CLKAO

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/VCP-Dest-svk/
COMMENT=	VCP destination driver for SVN/SVK repositories

DEPENDS+=	p5-VCP>=0.9beta20050110:../../devel/p5-VCP
DEPENDS+=	p5-YAML>=0.62:../../textproc/p5-YAML
DEPENDS+=	svk>=1.04:../../devel/svk

PERL5_PACKLIST=		auto/VCP/Dest/svk/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
