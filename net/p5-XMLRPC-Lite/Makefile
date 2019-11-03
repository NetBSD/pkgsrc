# $NetBSD: Makefile,v 1.7 2019/11/03 11:45:48 rillig Exp $

DISTNAME=	XMLRPC-Lite-0.717
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	net perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/P/PH/PHRED/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/P/PH/PHRED/
COMMENT=	Client and server implementation of XML-RPC protocol
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-SOAP-Lite-[0-9]*:../../net/p5-SOAP-Lite

PERL5_PACKLIST=	auto/XMLRPC-Lite/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
