# $NetBSD: Makefile,v 1.32 2022/06/28 11:32:26 wiz Exp $

DISTNAME=	File-LibMagic-1.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-LibMagic
COMMENT=	Perlwrapper for libmagic
LICENSE=	${PERL5_LICENSE}

BUILDLINK_API_DEPENDS.file+=	file>=5.00

DEPENDS+=	p5-Config-AutoConf-[0-9]*:../../devel/p5-Config-AutoConf

TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

# cannot open LibMagic.xs: No such file or directory
MAKE_JOBS_SAFE=	no

PERL5_PACKLIST=		auto/File/LibMagic/.packlist

.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
