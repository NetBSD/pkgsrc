# $NetBSD: Makefile,v 1.28 2022/06/28 11:35:11 wiz Exp $
#

DISTNAME=		Net-Ident-1.25
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Net-Ident
COMMENT=		Perl module implementing the client side of the ident protocol
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		#empty

PERL5_PACKLIST=		auto/Net/Ident/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
