# $NetBSD: Makefile,v 1.3 2011/08/14 15:14:12 obache Exp $

DISTNAME=	Text-German-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-German/
COMMENT=	German grundform reduction
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL+=		lib/Text/German.pm

PERL5_PACKLIST=		auto/Text/German/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
