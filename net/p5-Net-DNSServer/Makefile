# $NetBSD: Makefile,v 1.25 2022/06/28 11:35:09 wiz Exp $
#

DISTNAME=	Net-DNSServer-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	17
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module to be used as a domain name server

DEPENDS+=	p5-IPC-SharedCache-[0-9]*:../../devel/p5-IPC-SharedCache
DEPENDS+=	p5-Net-Bind-[0-9]*:../../net/p5-Net-Bind
DEPENDS+=	p5-Net-DNS>=0.19:../../net/p5-Net-DNS
DEPENDS+=	p5-Net-Server-[0-9]*:../../net/p5-Net-Server

PERL5_PACKLIST=	auto/Net/DNSServer/.packlist

post-extract:
	${RM} ${WRKSRC}/Net-DNSServer.spec.PL

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
