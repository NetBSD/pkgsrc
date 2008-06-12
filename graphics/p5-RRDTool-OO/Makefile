# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:32 joerg Exp $

DISTNAME=	RRDTool-OO-0.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSCHILLI/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/~mschilli/RRDTool-OO/
COMMENT=	Object-oriented interface to RRDTool

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	rrdtool-[0-9]*:../../databases/rrdtool

PERL5_PACKLIST=		auto/RRDTool/OO/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
