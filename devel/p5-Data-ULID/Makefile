# $NetBSD: Makefile,v 1.3 2026/07/16 19:02:14 wiz Exp $

DISTNAME=	Data-ULID-1.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-ULID
COMMENT=	Perl 5 module for Unique Lexicographically Sortable Identifier ULID
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Bytes-Random-Secure-Tiny-[0-9]*:../../security/p5-Bytes-Random-Secure-Tiny

PERL5_PACKLIST=		auto/Data/ULID/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
