# $NetBSD: Makefile,v 1.14 2023/07/06 09:41:16 wiz Exp $

DISTNAME=	XMLRPC-Lite-0.717
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PH/PHRED/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/XMLRPC::Lite
COMMENT=	Client and server implementation of XML-RPC protocol
LICENSE=	${PERL5_LICENSE}

# for make test
TOOL_DEPENDS+=	p5-SOAP-Lite-[0-9]*:../../net/p5-SOAP-Lite

PERL5_PACKLIST=	auto/XMLRPC-Lite/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
