# $NetBSD: Makefile,v 1.1.1.1 2004/11/04 21:42:25 he Exp $
#

DISTNAME=	SNMP-MIB-Compiler-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SNMP/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~ftassin/SNMP-MIB-Compiler-0.06/
COMMENT=	MIB Compiler supporting SMIv1 and SMIv2

USE_BUILDLINK3=		yes

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/SNMP/Mib/Compiler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
