# $NetBSD: Makefile,v 1.1 2013/08/26 00:54:50 wen Exp $
#

DISTNAME=	Pod-Markdown-1.322
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Markdown/
COMMENT=	Convert POD to Markdown
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Pod/Markdown/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
