# $NetBSD: Makefile,v 1.2 2011/08/14 12:26:19 obache Exp $
#

DISTNAME=	Module-Manifest-1.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Manifest/
COMMENT=	Parse and examine a Perl distribution MANIFEST file
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Warn>=0.11:../../devel/p5-Test-Warn

DEPENDS+=	p5-Params-Util>=0.10:../../devel/p5-Params-Util

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/Manifest/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
