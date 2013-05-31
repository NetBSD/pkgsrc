# $NetBSD: Makefile,v 1.21 2013/05/31 12:39:41 wiz Exp $

DISTNAME=	Net-AIM-1.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.aryeh.net/netaim.php
COMMENT=	Implementation of the AOL Instant Messenger TOC protocol
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Net/AIM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
