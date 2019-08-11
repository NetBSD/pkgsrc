# $NetBSD: Makefile,v 1.25 2019/08/11 13:22:15 wiz Exp $

DISTNAME=		IO-Socket-INET6-2.72
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/IO-Socket-INET6
COMMENT=		Perl object interface for AF_INET/AF_INET6 domain sockets
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Socket6>=0.12:../../net/p5-Socket6

SUPERSEDES=		p5-INET6-[0-9]*

PERL5_PACKLIST=		auto/IO/Socket/INET6/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
