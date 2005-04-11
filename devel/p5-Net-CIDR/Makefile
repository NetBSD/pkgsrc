# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:33 tv Exp $
#

DISTNAME=	Net-CIDR-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module to manipulate IPv4/IPv6 netblocks in CIDR notation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/CIDR/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
