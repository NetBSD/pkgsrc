# $NetBSD: Makefile,v 1.20 2023/07/06 09:41:08 wiz Exp $

DISTNAME=	Net-Interface-1.016
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MIKER/${DISTNAME}
COMMENT=	Perl extension to access network interfaces
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/Interface/.packlist

REPLACE_PERL+=		inst/netsymbols.pl

pre-configure:
	${FIND} ${WRKSRC} -name '*.orig' -print -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
