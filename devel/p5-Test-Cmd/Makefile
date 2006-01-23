# $NetBSD: Makefile,v 1.14 2006/01/23 12:03:20 wulf Exp $

DISTNAME=	Test-Cmd-1.05
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5tcm
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	http://www.baldmt.com/Test-Cmd/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.baldmt.com/Test-Cmd/
COMMENT=	Perl5 module for testing of external commands and scripts

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Test/Cmd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
