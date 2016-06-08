# $NetBSD: Makefile,v 1.38 2016/06/08 19:22:47 wiz Exp $

DISTNAME=	Data-UUID-1.221
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-UUID/
COMMENT=	Perl module for generating UUIDs
LICENSE=	modified-bsd

#DEPENDS+=		{perl>=5.7.3,p5-Digest-MD5>=0}:../../security/p5-Digest-MD5

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Data/UUID/.packlist

OPSYSVARS+=		MAKE_PARAMS
MAKE_PARAMS.Darwin+=	DEFINE=-D_POSIX_C_SOURCE

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
