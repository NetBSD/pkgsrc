# $NetBSD: Makefile,v 1.25 2014/01/01 11:52:30 wiz Exp $

DISTNAME=		Net-Z3950-ZOOM-1.28
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		9
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Net-Z3950-ZOOM/
COMMENT=		Perl extension for talking to Z39.50 servers
LICENSE=		${PERL5_LICENSE}

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=     p5-Event>=1.06:../../devel/p5-Event
DEPENDS+=     p5-MARC-Record>=2.0.0:../../databases/p5-MARC-Record
BUILDLINK_API_DEPENDS.yaz+=	yaz>=2.1.50

PERL5_PACKLIST=	auto/Net/Z3950/ZOOM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
