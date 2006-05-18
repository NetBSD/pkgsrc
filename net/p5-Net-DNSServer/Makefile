# $NetBSD: Makefile,v 1.8 2006/05/18 20:30:00 wiz Exp $
#

DISTNAME=	Net-DNSServer-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module to be used as a domain name server

BROKEN_IN=	pkgsrc-2006Q1

DEPENDS+=	p5-IPC-SharedCache-[0-9]*:../../devel/p5-IPC-SharedCache
DEPENDS+=	p5-Net-Bind-[0-9]*:../../net/p5-Net-Bind
DEPENDS+=	p5-Net-Server-[0-9]*:../../net/p5-Net-Server

PERL5_PACKLIST=	auto/Net/DNSServer/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
