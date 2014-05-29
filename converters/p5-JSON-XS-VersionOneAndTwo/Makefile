# $NetBSD: Makefile,v 1.8 2014/05/29 23:35:22 wiz Exp $

DISTNAME=	JSON-XS-VersionOneAndTwo-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	textproc perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LB/LBROCARD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/JSON-XS-VersionOneAndTwo/
COMMENT=	Support versions 1 and 2 of JSON::XS
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/JSON/XS/VersionOneAndTwo/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
