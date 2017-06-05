# $NetBSD: Makefile,v 1.3 2017/06/05 14:24:51 ryoon Exp $
#

DISTNAME=		Text-Roman-3.5
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Text-Roman/
COMMENT=		Allows conversion between Roman and Arabic algarisms
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/Roman/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
