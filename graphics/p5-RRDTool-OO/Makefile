# $NetBSD: Makefile,v 1.3 2008/07/13 16:04:03 rhaen Exp $

DISTNAME=	RRDTool-OO-0.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSCHILLI/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/~mschilli/RRDTool-OO/
COMMENT=	Object-oriented interface to RRDTool

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	rrdtool-[0-9]*:../../databases/rrdtool
DEPENDS+=	p5-Log-Log4perl>=0.4:../../devel/p5-Log-Log4perl

PERL5_PACKLIST=		auto/RRDTool/OO/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
