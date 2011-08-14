# $NetBSD: Makefile,v 1.9 2011/08/14 12:26:16 obache Exp $
#

DISTNAME=	Log-LogLite-0.82
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5llt
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Log-LogLite/
COMMENT=	Simple logging class for Perl

DEPENDS+=	p5-IO-LockedFile>=0.23:../../devel/p5-IO-LockedFile

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Log/LogLite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
