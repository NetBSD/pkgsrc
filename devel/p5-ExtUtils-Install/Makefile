# $NetBSD: Makefile,v 1.7 2011/08/12 12:54:07 adam Exp $

DISTNAME=	ExtUtils-Install-1.54
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-Install/
COMMENT=	Install files from here to there
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/ExtUtils/Install/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
