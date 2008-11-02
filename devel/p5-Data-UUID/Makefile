# $NetBSD: Makefile,v 1.15 2008/11/02 16:20:20 he Exp $

PNAME=		Data-UUID
DISTNAME=	${PNAME}-1.149
PKGNAME=	p5-${PNAME}-1.14.9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-UUID/
COMMENT=	Perl module for generating UUIDs

DEPENDS+=	p5-Digest-MD5>0:../../security/p5-Digest-MD5

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=	c

PERL5_PACKLIST=		auto/Data/UUID/.packlist

MAKE_ENV+=		PERL_MM_USE_DEFAULT=1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
MAKE_PARAMS+=		DEFINE=-D_POSIX_C_SOURCE
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
