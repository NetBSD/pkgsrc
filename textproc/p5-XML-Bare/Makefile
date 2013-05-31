# $NetBSD: Makefile,v 1.5 2013/05/31 12:42:19 wiz Exp $
#

DISTNAME=	XML-Bare-0.52
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Bare/
COMMENT=	Minimal XML parser implemented via a C state engine
LICENSE=	gnu-gpl-v2

PERL5_PACKLIST=	auto/XML/Bare/.packlist
USE_LANGUAGES=	c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
