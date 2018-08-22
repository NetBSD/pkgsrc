# $NetBSD: Makefile,v 1.24 2018/08/22 09:44:01 wiz Exp $

DISTNAME=	File-LibMagic-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-LibMagic/
COMMENT=	Perlwrapper for libmagic
LICENSE=	${PERL5_LICENSE}

BUILDLINK_API_DEPENDS.file+=	file>=5.00

# necessary for test
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

# incompatible change in MakeMaker 7.06 vs. 7.04.1 in object file location
# => enforce the new behaviour
# Behavior back to 7.04.1
BUILD_DEPENDS+= p5-ExtUtils-MakeMaker>=7.10:../../devel/p5-ExtUtils-MakeMaker

# cannot open LibMagic.xs: No such file or directory
MAKE_JOBS_SAFE=	no

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/File/LibMagic/.packlist

.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
