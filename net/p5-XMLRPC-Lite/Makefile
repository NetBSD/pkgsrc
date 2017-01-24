# $NetBSD: Makefile,v 1.1 2017/01/24 13:45:36 mef Exp $

DISTNAME=	XMLRPC-Lite-0.717
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/P/PH/PHRED/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/P/PH/PHRED/
COMMENT=	Client and server implementation of XML-RPC protocol
LICENSE=        ${PERL5_LICENSE}

PERL5_PACKLIST= auto/XMLRPC-Lite/.packlist
USE_LANGUAGES=  # none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
