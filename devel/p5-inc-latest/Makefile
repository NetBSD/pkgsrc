# $NetBSD: Makefile,v 1.5 2019/06/30 20:16:04 nia Exp $

DISTNAME=	inc-latest-0.500
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/D/DA/DAGOLDEN/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/inc-latest
COMMENT=	Use modules bundled in inc/ if they are newer than installed ones
LICENSE=	apache-2.0

PERL5_PACKLIST=		auto/inc/latest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
