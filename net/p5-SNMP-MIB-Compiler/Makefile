# $NetBSD: Makefile,v 1.26 2023/07/06 09:41:14 wiz Exp $
#

DISTNAME=	SNMP-MIB-Compiler-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	18
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SNMP/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SNMP-MIB-Compiler
COMMENT=	MIB Compiler supporting SMIv1 and SMIv2

PERL5_PACKLIST=		auto/SNMP/MIB/Compiler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
