# $NetBSD: Makefile,v 1.34 2009/03/10 17:21:27 sno Exp $

DISTNAME=		Archive-Tar-1.46
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tar
CATEGORIES=		archivers perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Archive-Tar/
COMMENT=		Perl5 module interface to manipulate tar files

DEPENDS+=		p5-IO-Zlib>=1.01:../../devel/p5-IO-Zlib
DEPENDS+=		p5-IO-Compress-Bzip2>=2.012:../../devel/p5-IO-Compress-Bzip2
DEPENDS+=		p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=		p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_PARAMS+=		"-d"	# Text::Diff is a prerequisite
PERL5_PACKLIST=		auto/Archive/Tar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
