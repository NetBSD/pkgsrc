# $NetBSD: Makefile,v 1.12 2005/07/13 18:01:29 jlam Exp $

DISTNAME=	Test-Cmd-1.04
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5tcm
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	http://www.baldmt.com/Test-Cmd/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.baldmt.com/Test-Cmd/
COMMENT=	Perl5 module for testing of external commands and scripts

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Test/Cmd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
