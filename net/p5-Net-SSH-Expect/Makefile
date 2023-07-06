# $NetBSD: Makefile,v 1.13 2023/07/06 09:41:11 wiz Exp $

DISTNAME=	Net-SSH-Expect-1.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/libnet
COMMENT=	Perl5 module implementing expect-like functions over SSH
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/SSH/Expect/.packlist

DEPENDS+=	p5-Expect>=1.14:../../devel/p5-Expect

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
