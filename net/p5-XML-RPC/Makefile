# $NetBSD: Makefile,v 1.2 2017/06/05 14:24:25 ryoon Exp $

DISTNAME=	XML-RPC-0.9
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 net
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DA/DAAN/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/D/DA/DAAN/
COMMENT=	Pure Perl implementation for an XML-RPC client and server
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST= auto/XML-RPC/.packlist
USE_LANGUAGES=  # none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
