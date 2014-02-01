# $NetBSD: Makefile,v 1.24 2014/02/01 12:30:04 wen Exp $

DISTNAME=	Tree-DAG_Node-1.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tree/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dprice@cs.nmsu.edu
HOMEPAGE=	http://search.cpan.org/dist/Tree-DAG_Node/
COMMENT=	Class for representing nodes in a tree
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.19.1,p5-File-Temp>=0.23.01}:../../devel/p5-File-Temp
DEPENDS+=	p5-File-Temp>=0.19:../../devel/p5-File-Temp
DEPENDS+=	p5-File-Slurp>=9999.19:../../devel/p5-File-Slurp

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Tree/DAG_Node/.packlist

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
