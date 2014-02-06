# $NetBSD: Makefile,v 1.56 2014/02/06 12:25:52 abs Exp $

DISTNAME=	Archive-Tar-1.96
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tar
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Archive-Tar/
COMMENT=	Perl5 module interface to manipulate tar files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.9.3,p5-IO-Zlib>=1.01}:../../devel/p5-IO-Zlib
# IO::Compress::{Base,Gzip,Bzip2} are included since perl-5.10.1
DEPENDS+=	{perl>=5.10.1,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress
DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_PARAMS+=		"-d"	# Text::Diff is a prerequisite
PERL5_PACKLIST=		auto/Archive/Tar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
