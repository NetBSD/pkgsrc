# $NetBSD: Makefile,v 1.2 2002/10/20 17:46:01 seb Exp $
#

DISTNAME=	Net-ICQ2000-0.2.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	chat perl5
MASTER_SITES=	http://gonzo.kiev.ua/projects/vicq/

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://icq2000.phase3solutions.com/
COMMENT=	perl5 modules for the ICQv7 protocol realisation

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/ICQ2000/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
