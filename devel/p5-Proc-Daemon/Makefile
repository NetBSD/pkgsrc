# $NetBSD: Makefile,v 1.7 2005/07/13 18:01:28 jlam Exp $
#

DISTNAME=	Proc-Daemon-0.03
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5prd
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://www.nacs.uci.edu/indiv/ehood/earlsperls.html
COMMENT=	Provide capability for a Perl program to run as a daemon

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Proc/Daemon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
