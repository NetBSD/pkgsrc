# $NetBSD: Makefile,v 1.1.1.1 2008/09/10 18:53:49 he Exp $

DISTNAME=	POE-Component-Pluggable-1.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Component-Pluggable/
COMMENT=	Perl base class for creating plugin enabled POE Components

DEPENDS+=	p5-POE>=1.0002:../../devel/p5-POE

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/POE/Component/Pluggable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
