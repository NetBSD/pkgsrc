# $NetBSD: Makefile,v 1.22 2019/08/11 13:19:28 wiz Exp $

DISTNAME=	File-ShareDir-1.116
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-ShareDir
COMMENT=	Get a generic path to the share directory
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Inspector>=1.12:../../devel/p5-Class-Inspector

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Install::Bundled
PERL5_PACKLIST=		auto/File/ShareDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
