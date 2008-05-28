# $NetBSD: Makefile,v 1.7 2008/05/28 21:10:32 abs Exp $
#

DISTNAME=	Tree-DAG_Node-1.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tree/}

MAINTAINER=	dprice@cs.nmsu.edu
HOMEPAGE=	http://search.cpan.org/dist/Tree-DAG_Node/
COMMENT=	Class for representing nodes in a tree

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Tree/DAG_Node/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
