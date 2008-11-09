# $NetBSD: Makefile,v 1.1.1.1 2008/11/09 13:05:37 obache Exp $

DISTNAME=	Pod-Readme-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Readme/
COMMENT=	Convert POD to README file

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Regexp-Common>=0:../../textproc/p5-Regexp-Common

PERL5_PACKLIST=		auto/Pod/Readme/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
