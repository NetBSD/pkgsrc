# $NetBSD: Makefile,v 1.4 2013/05/31 12:41:42 wiz Exp $
#

DISTNAME=	SOAP-Transport-TCP-0.715
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SOAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SOAP-Transport-TCP
COMMENT=	TCP transport layer for SOAP::Lite
LICENSE=	artistic

CONFLICTS+=	p5-SOAP-Lite<0.714
DEPENDS+=	p5-SOAP-Lite>=0.714:../../net/p5-SOAP-Lite

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/SOAP/Transport/TCP/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
