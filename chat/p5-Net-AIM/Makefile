# $NetBSD: Makefile,v 1.8 2004/12/20 11:30:56 grant Exp $
#

DISTNAME=	Net-AIM-1.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.aryeh.net/Net-AIM/
COMMENT=	Implementation of the AOL Instant Messenger TOC protocol

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/AIM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
