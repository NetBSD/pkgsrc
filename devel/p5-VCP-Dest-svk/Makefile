# $NetBSD: Makefile,v 1.1.1.1 2006/05/02 02:59:03 jlam Exp $

DISTNAME=	VCP-Dest-svk-0.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/C/CL/CLKAO

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/VCP-Dest-svk/
COMMENT=	VCP destination driver for SVN/SVK repositories

DEPENDS+=	p5-VCP>=0.9beta20050110:../../devel/p5-VCP
DEPENDS+=	svk>=1.04:../../devel/svk

PERL5_PACKLIST=		auto/VCP/Dest/svk/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
