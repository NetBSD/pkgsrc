# $NetBSD: Makefile,v 1.9 2005/04/11 21:45:05 tv Exp $
#

DISTNAME=	Net-AIM-1.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.aryeh.net/Net-AIM/
COMMENT=	Implementation of the AOL Instant Messenger TOC protocol

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/AIM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
