# $NetBSD: Makefile,v 1.20 2023/07/06 09:40:25 wiz Exp $
#

DISTNAME=	UUID-Tiny-1.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=UUID/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/UUID-Tiny
COMMENT=	Pure Perl UUID Support With Functional Interface
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/UUID/Tiny/.packlist

#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
