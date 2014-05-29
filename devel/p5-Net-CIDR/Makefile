# $NetBSD: Makefile,v 1.18 2014/05/29 23:36:09 wiz Exp $
#

DISTNAME=	Net-CIDR-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-CIDR/
COMMENT=	Perl5 module to manipulate IPv4/IPv6 netblocks in CIDR notation
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Net/CIDR/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
