# $NetBSD: Makefile,v 1.4 2015/02/14 12:42:44 mef Exp $

DISTNAME=	PerlIO-utf8_strict-0.005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PerlIO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl extension to provide fast and correct UTF-8 I/O
HOMEPAGE=	http://search.cpan.org/dist/PerlIO-utf8_strict/
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES+=	c

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/PerlIO/utf8_strict/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
