# $NetBSD: Makefile,v 1.3 2004/12/20 11:31:06 grant Exp $
#

DISTNAME=	Net-Gnats-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnatsperl/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gnatsperl.sourceforge.net/
COMMENT=	Perl interface to the gnatsd daemon

USE_BUILDLINK3=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/Gnats/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
