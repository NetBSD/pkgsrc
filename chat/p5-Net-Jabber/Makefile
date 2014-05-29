# $NetBSD: Makefile,v 1.19 2014/05/29 23:35:19 wiz Exp $

DISTNAME=	Net-Jabber-2.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~reatmon/Net-Jabber-2.0/
#HOMEPAGE=	http://www.jabber.org/
COMMENT=	Provide a Perl Developer access to the Jabber protocol

DEPENDS+=	p5-Net-XMPP>=1.0:../../net/p5-Net-XMPP

PERL5_PACKLIST=	auto/Net/Jabber/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
