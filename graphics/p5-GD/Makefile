# $NetBSD: Makefile,v 1.99 2023/11/12 13:22:10 wiz Exp $

DISTNAME=	GD-2.76
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/GD
COMMENT=	Perl5 interface to gd graphics library
LICENSE=	gnu-gpl-v2 OR artistic-2.0

TOOL_DEPENDS+=	p5-ExtUtils-PkgConfig>=1:../../devel/p5-ExtUtils-PkgConfig

USE_TOOLS+=	pkg-config

# This is required at least on some Solaris builds to get a runnable
# package, and should be harmless on other platforms. See PR 45873.
CFLAGS+=		-D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64

PERL5_PACKLIST=		auto/GD/.packlist
PERL5_OPTIONS+=		threads

# stop package's GetOptions() from parsing Module::Build settings
MAKE_PARAMS+=	--

post-extract:
	chmod a+w ${WRKSRC}/bdf_scripts/bdf2gdfont_pl.PL

.include "../../converters/libiconv/buildlink3.mk"
BUILDLINK_API_DEPENDS.gd+=	gd>=2.0.28
.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
