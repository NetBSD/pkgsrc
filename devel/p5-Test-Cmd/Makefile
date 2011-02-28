# $NetBSD: Makefile,v 1.19 2011/02/28 14:52:45 wiz Exp $

DISTNAME=	Test-Cmd-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5tcm
CATEGORIES=	devel perl5
MASTER_SITES=	http://www.baldmt.com/Test-Cmd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.baldmt.com/Test-Cmd/
COMMENT=	Perl5 module for testing of external commands and scripts

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Test/Cmd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
