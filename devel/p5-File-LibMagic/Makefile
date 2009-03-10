# $NetBSD: Makefile,v 1.2 2009/03/10 23:35:02 he Exp $

DISTNAME=	File-LibMagic-0.91
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-LibMagic/
COMMENT=	Perlwrapper for libmagic

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.file+=	file>=5.00

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/File/LibMagic/.packlist

.include "../../sysutils/file/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
