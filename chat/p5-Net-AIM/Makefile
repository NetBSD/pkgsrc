# $NetBSD: Makefile,v 1.4 2002/10/09 00:51:47 schmonz Exp $
#

DISTNAME=	Net-AIM-1.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	schmonz@netbsd.org
HOMEPAGE=	http://www.aryeh.net/Net-AIM/
COMMENT=	implementation of the AOL Instant Messenger TOC protocol

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/AIM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
