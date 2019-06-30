# $NetBSD: Makefile,v 1.39 2019/06/30 20:16:00 nia Exp $

DISTNAME=	Tree-DAG_Node-1.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tree/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dprice@cs.nmsu.edu
HOMEPAGE=	https://metacpan.org/release/Tree-DAG_Node
COMMENT=	Class for representing nodes in a tree
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.19.1,p5-File-Temp>=0.23.01}:../../devel/p5-File-Temp
DEPENDS+=	p5-File-Slurp-Tiny>=0:../../devel/p5-File-Slurp-Tiny

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Tree/DAG_Node/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
