# $NetBSD: Makefile,v 1.1.1.1 2003/03/04 16:26:37 seb Exp $
#

DISTNAME=	Config-General-2.15
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cfg
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	sketch@rd.bbc.co.uk
HOMEPAGE=	http://www.daemon.de/config-general/
COMMENT=	Perl Generic Config module

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Config/General/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
