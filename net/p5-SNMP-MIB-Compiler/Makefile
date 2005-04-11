# $NetBSD: Makefile,v 1.5 2005/04/11 21:46:56 tv Exp $
#

DISTNAME=	SNMP-MIB-Compiler-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SNMP/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SNMP-MIB-Compiler/
COMMENT=	MIB Compiler supporting SMIv1 and SMIv2


PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/SNMP/Mib/Compiler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
