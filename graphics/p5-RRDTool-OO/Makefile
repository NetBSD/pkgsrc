# $NetBSD: Makefile,v 1.9 2011/08/14 12:59:50 obache Exp $

DISTNAME=	RRDTool-OO-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSCHILLI/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/~mschilli/RRDTool-OO/
COMMENT=	Object-oriented interface to RRDTool
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	rrdtool>=1.2.0:../../databases/rrdtool
DEPENDS+=	p5-Log-Log4perl>=0.4:../../devel/p5-Log-Log4perl

PERL5_PACKLIST=		auto/RRDTool/OO/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
