# $NetBSD: Makefile,v 1.14 2012/07/13 07:46:45 sno Exp $
#

DISTNAME=	Text-Format-0.56
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tfo
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Format/
COMMENT=	Provide perl5 formatting functions on plain text
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Text/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
