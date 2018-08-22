# $NetBSD: Makefile,v 1.27 2018/08/22 09:47:00 wiz Exp $
#

DISTNAME=	Text-Format-0.61
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Format/
COMMENT=	Provide perl5 formatting functions on plain text
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Text/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
