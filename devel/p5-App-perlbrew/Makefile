# $NetBSD: Makefile,v 1.6 2011/08/07 07:52:46 adam Exp $

DISTNAME=	App-perlbrew-0.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-perlbrew/
COMMENT=	Manage perl installations in your $$HOME
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/App/perlbrew/.packlist

DEPENDS+=	p5-File-Path-Tiny>=0.1:../../devel/p5-File-Path-Tiny
DEPENDS+=	p5-HTTP-Lite>=2.2:../../www/p5-HTTP-Lite

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
