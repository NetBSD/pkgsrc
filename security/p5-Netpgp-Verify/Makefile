# $NetBSD: Makefile,v 1.5 2019/08/11 13:22:58 wiz Exp $

DISTNAME=	p5-Netpgp-Verify-20160814
PKGREVISION=	3
CATEGORIES=	security perl5
MASTER_SITES=	https://agc.ac/src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://agc.ac/
COMMENT=	Perl5 bindings for libnetpgpverify
LICENSE=	modified-bsd

PERL5_PACKLIST=		auto/Netpgp/Verify/.packlist

.include "../../security/libnetpgpverify/buildlink3.mk"

.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
