# $NetBSD: Makefile,v 1.1.1.1 2003/12/09 04:53:57 grant Exp $
#

DISTNAME=	Net-CIDR-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module to manipulate IPv4/IPv6 netblocks in CIDR notation

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/CIDR/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
