# $NetBSD: Makefile,v 1.13 2017/06/05 14:24:08 ryoon Exp $

DISTNAME=	Net-ManageSieve-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-ManageSieve/
COMMENT=	ManageSieve Protocol Client
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/ManageSieve/.packlist

post-patch:
	rm ${WRKSRC}/lib/Net/ManageSieve.pm.orig

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
