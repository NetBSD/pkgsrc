# $NetBSD: Makefile,v 1.25 2023/07/06 09:40:39 wiz Exp $

DISTNAME=	RRDTool-OO-0.36
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSCHILLI/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	https://metacpan.org/release/RRDTool-OO
COMMENT=	Object-oriented interface to RRDTool
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	rrdtool>=1.2.11:../../databases/rrdtool
DEPENDS+=	p5-Log-Log4perl>=0.4:../../devel/p5-Log-Log4perl

PERL5_PACKLIST=		auto/RRDTool/OO/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
