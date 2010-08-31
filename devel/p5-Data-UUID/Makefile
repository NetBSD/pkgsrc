# $NetBSD: Makefile,v 1.21 2010/08/31 20:57:53 sno Exp $

DISTNAME=	Data-UUID-1.215
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-UUID/
COMMENT=	Perl module for generating UUIDs
LICENSE=	modified-bsd

DEPENDS+=	{perl>=5.10,p5-Digest-MD5>0}:../../security/p5-Digest-MD5

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=	c

PERL5_PACKLIST=		auto/Data/UUID/.packlist

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
MAKE_PARAMS+=		DEFINE=-D_POSIX_C_SOURCE
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
