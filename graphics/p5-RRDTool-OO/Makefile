# $NetBSD: Makefile,v 1.1.1.1 2006/06/07 11:50:51 abs Exp $

DISTNAME=	RRDTool-OO-0.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSCHILLI/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/~mschilli/RRDTool-OO/
COMMENT=	Object-oriented interface to RRDTool

DEPENDS+=	rrdtool-[0-9]*:../../databases/rrdtool

PERL5_PACKLIST=		auto/RRDTool/OO/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
