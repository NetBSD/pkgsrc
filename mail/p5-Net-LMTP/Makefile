# $NetBSD: Makefile,v 1.18 2019/07/01 21:50:09 nia Exp $
#

DISTNAME=	Net-LMTP-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/LHOWARD/${DISTNAME}
COMMENT=	Local Mail Transfer Protocol Client

PERL5_PACKLIST=	auto/Net/LMTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
