# $NetBSD: Makefile,v 1.2 2004/04/25 03:27:08 minskim Exp $
#

DISTNAME=	Proc-Daemon-0.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5prd
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	sketch@rd.bbc.co.uk
HOMEPAGE=	http://www.nacs.uci.edu/indiv/ehood/earlsperls.html
COMMENT=	Provide capability for a Perl program to run as a daemon

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Proc/Daemon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
