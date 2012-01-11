# $NetBSD: Makefile,v 1.1.1.1 2012/01/11 04:31:37 schmonz Exp $
#

DISTNAME=		Text-Typography-0.01
PKGNAME=		p5-${DISTNAME}
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
