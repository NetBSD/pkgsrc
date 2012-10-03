# $NetBSD: Makefile,v 1.8 2012/10/03 21:55:02 wiz Exp $

DISTNAME=	File-ShareDir-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-p5-people@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-ShareDir/
COMMENT=	Get a generic path to the share directory
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Inspector>=1.12:../../devel/p5-Class-Inspector

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Install::Bundled
PERL5_PACKLIST=		auto/File/ShareDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
