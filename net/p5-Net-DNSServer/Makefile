# $NetBSD: Makefile,v 1.1.1.1 2004/04/09 12:35:19 grant Exp $
#

DISTNAME=	Net-DNSServer-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module to be used as a domain name server

DEPENDS+=	p5-IPC-SharedCache-[0-9]*:../../devel/p5-IPC-SharedCache
DEPENDS+=	p5-Net-Bind-[0-9]*:../../net/p5-Net-Bind
DEPENDS+=	p5-Net-Server-[0-9]*:../../net/p5-Net-Server

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/DNSServer/.packlist

.include "../../databases/p5-DBI/buildlink2.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
