# $NetBSD: Makefile,v 1.28 2013/05/31 12:40:13 wiz Exp $

DISTNAME=	Data-UUID-1.218
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-UUID/
COMMENT=	Perl module for generating UUIDs
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=		p5-Digest-MD5>=0:../../security/p5-Digest-MD5

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Data/UUID/.packlist

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
MAKE_PARAMS+=		DEFINE=-D_POSIX_C_SOURCE
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
