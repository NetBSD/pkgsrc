# $NetBSD: Makefile,v 1.60 2022/06/28 11:35:15 wiz Exp $

DISTNAME=		Net-Z3950-ZOOM-1.30
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		27
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Net-Z3950-ZOOM
COMMENT=		Perl extension for talking to Z39.50 servers
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-Event>=1.06:../../devel/p5-Event
DEPENDS+=	p5-MARC-Record>=2.0.0:../../databases/p5-MARC-Record
BUILDLINK_API_DEPENDS.yaz+=	yaz>=4

PERL5_PACKLIST=	auto/Net/Z3950/ZOOM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
