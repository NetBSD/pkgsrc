# $NetBSD: Makefile,v 1.15 2015/06/12 10:50:13 wiz Exp $

DISTNAME=	RRDTool-OO-0.35
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSCHILLI/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/~mschilli/RRDTool-OO/
COMMENT=	Object-oriented interface to RRDTool
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	rrdtool>=1.2.11:../../databases/rrdtool
DEPENDS+=	p5-Log-Log4perl>=0.4:../../devel/p5-Log-Log4perl

PERL5_PACKLIST=		auto/RRDTool/OO/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
