# $NetBSD: Makefile,v 1.10 2013/05/31 12:40:20 wiz Exp $

DISTNAME=	File-LibMagic-0.96
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-LibMagic/
COMMENT=	Perlwrapper for libmagic
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILDLINK_API_DEPENDS.file+=	file>=5.00

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/File/LibMagic/.packlist

.include "../../sysutils/file/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
