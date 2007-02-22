# $NetBSD: Makefile,v 1.15 2007/02/22 19:26:23 wiz Exp $

DISTNAME=	Test-Cmd-1.05
PKGNAME=	p5-${DISTNAME}
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
