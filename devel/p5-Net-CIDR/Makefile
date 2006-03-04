# $NetBSD: Makefile,v 1.8 2006/03/04 21:29:23 jlam Exp $
#

DISTNAME=	Net-CIDR-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module to manipulate IPv4/IPv6 netblocks in CIDR notation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Net/CIDR/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
