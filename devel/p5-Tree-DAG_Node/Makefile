# $NetBSD: Makefile,v 1.1.1.1 2005/01/08 13:40:17 minskim Exp $
#

DISTNAME=	Tree-DAG_Node-1.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://cpan.org/authors/id/S/SB/SBURKE/

MAINTAINER=	dprice@cs.nmsu.edu
HOMEPAGE=	http://cpan.org/authors/id/S/SB/SBURKE/Tree-DAG_Node-1.05.readme
COMMENT=	Class for representing nodes in a tree

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Tree/DAG_Node/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
