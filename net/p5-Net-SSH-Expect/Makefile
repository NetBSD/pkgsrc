# $NetBSD: Makefile,v 1.1 2014/09/23 10:53:09 he Exp $

DISTNAME=	Net-SSH-Expect-1.09
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5nse
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/libnet/
COMMENT=	Perl5 module implementing expect-like functions over SSH
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Net/SSH/Expect/.packlist

DEPENDS+=	p5-Expect>=1.14:../../devel/p5-Expect

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
