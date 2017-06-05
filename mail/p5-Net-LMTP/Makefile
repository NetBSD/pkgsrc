# $NetBSD: Makefile,v 1.16 2017/06/05 14:24:07 ryoon Exp $
#

DISTNAME=	Net-LMTP-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~lhoward/${DISTNAME}/
COMMENT=	Local Mail Transfer Protocol Client

PERL5_PACKLIST=	auto/Net/LMTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
