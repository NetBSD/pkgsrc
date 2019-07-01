# $NetBSD: Makefile,v 1.5 2019/07/01 21:35:50 nia Exp $

DISTNAME=	XML-RPC-1.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 net
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/C/CA/CAVAC/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-RPC
COMMENT=	Pure Perl implementation for an XML-RPC client and server
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-TreePP-[0-9]*:../../textproc/p5-XML-TreePP

PERL5_PACKLIST= auto/XML/RPC/.packlist
USE_LANGUAGES=  # none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
