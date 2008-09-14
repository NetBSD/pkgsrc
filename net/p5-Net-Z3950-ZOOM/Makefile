# $NetBSD: Makefile,v 1.1.1.1 2008/09/14 19:32:55 he Exp $

DISTNAME=		Net-Z3950-ZOOM-1.24
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Net-Z3950-ZOOM/
COMMENT=		Perl extension for talking to Z39.50 servers

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=     p5-Event>=1.06:../../devel/p5-Event
DEPENDS+=     p5-MARC-Record>=2.0.0:../../wip/p5-MARC-Record
BUILDLINK_API_DEPENDS.yaz+=	yaz>=2.1.50

PERL5_PACKLIST=	auto/Net/Z3950/ZOOM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
