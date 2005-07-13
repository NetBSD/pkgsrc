# $NetBSD: Makefile,v 1.12 2005/07/13 18:01:30 jlam Exp $
#

DISTNAME=	gettext-1.04
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5gtx
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/gettext/
COMMENT=	Perl5 module interface to C I18N functions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Locale/gettext/.packlist

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
