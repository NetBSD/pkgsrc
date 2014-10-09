# $NetBSD: Makefile,v 1.3 2014/10/09 14:06:47 wiz Exp $

DISTNAME=	Net-SSH-Expect-1.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/libnet/
COMMENT=	Perl5 module implementing expect-like functions over SSH
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/SSH/Expect/.packlist

DEPENDS+=	p5-Expect>=1.14:../../devel/p5-Expect

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
