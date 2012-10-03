# $NetBSD: Makefile,v 1.2 2012/10/03 21:58:06 wiz Exp $
#

DISTNAME=		Text-Typography-0.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Text-Typography
COMMENT=		Markup ASCII text with correct typography for HTML
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/Typography/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
