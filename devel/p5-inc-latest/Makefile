# $NetBSD: Makefile,v 1.3 2017/06/05 14:23:54 ryoon Exp $

DISTNAME=	inc-latest-0.500
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/D/DA/DAGOLDEN/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/inc-latest/
COMMENT=	Use modules bundled in inc/ if they are newer than installed ones
LICENSE=	apache-2.0

PERL5_PACKLIST=		auto/inc/latest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
