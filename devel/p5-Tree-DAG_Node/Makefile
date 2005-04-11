# $NetBSD: Makefile,v 1.3 2005/04/11 21:45:35 tv Exp $
#

DISTNAME=	Tree-DAG_Node-1.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://cpan.org/authors/id/S/SB/SBURKE/

MAINTAINER=	dprice@cs.nmsu.edu
HOMEPAGE=	http://search.cpan.org/dist/Tree-DAG_Node/
COMMENT=	Class for representing nodes in a tree

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Tree/DAG_Node/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
