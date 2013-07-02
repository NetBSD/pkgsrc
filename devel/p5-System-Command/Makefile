# $NetBSD: Makefile,v 1.7 2013/07/02 14:47:19 wen Exp $

DISTNAME=	System-Command-1.100
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=System/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/System-Command/
COMMENT=	Object for running system commands
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/System/Command/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
