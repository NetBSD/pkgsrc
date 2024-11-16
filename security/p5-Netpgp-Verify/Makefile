# $NetBSD: Makefile,v 1.10 2024/11/16 12:06:35 wiz Exp $

DISTNAME=	p5-Netpgp-Verify-20160814
PKGREVISION=	8
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
