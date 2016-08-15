# $NetBSD: Makefile,v 1.1 2016/08/15 06:18:34 agc Exp $

DISTNAME=	p5-Netpgp-Verify-20160814
CATEGORIES=	security perl5
MASTER_SITES=	http://www.netpgp.com/src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.netpgp.com/
COMMENT=	Perl5 bindings for libnetpgpverify
LICENSE=	modified-bsd

PERL5_PACKLIST=		auto/Netpgp/Verify/.packlist

.include "../../security/libnetpgpverify/buildlink3.mk"

.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
