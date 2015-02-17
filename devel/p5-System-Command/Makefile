# $NetBSD: Makefile,v 1.11 2015/02/17 05:35:51 mef Exp $

DISTNAME=	System-Command-1.111
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=System/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/System-Command/
COMMENT=	Object for running system commands
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/System/Command/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
