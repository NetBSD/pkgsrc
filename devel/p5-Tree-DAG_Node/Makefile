# $NetBSD: Makefile,v 1.6 2008/01/08 23:41:06 heinz Exp $
#

DISTNAME=	Tree-DAG_Node-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tree/}

MAINTAINER=	dprice@cs.nmsu.edu
HOMEPAGE=	http://search.cpan.org/dist/Tree-DAG_Node/
COMMENT=	Class for representing nodes in a tree

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Tree/DAG_Node/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
