# $NetBSD: Makefile,v 1.3 2011/08/14 08:18:11 obache Exp $
#

DISTNAME=	YAML-MLDBM-0.10
PKGNAME=	p5-${DISTNAME:S/_/beta/}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=YAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/YAML-MLDBM/
COMMENT=	Use tied hash db-s with Python and Ruby
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-MLDBM>=2.01:../../databases/p5-MLDBM
DEPENDS+=	p5-YAML>=0.35:../../textproc/p5-YAML

PERL5_PACKLIST=	auto/YAML/MLDBM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
