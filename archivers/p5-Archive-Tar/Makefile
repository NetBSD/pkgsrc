# $NetBSD: Makefile,v 1.25 2007/06/08 08:33:50 wiz Exp $

DISTNAME=		Archive-Tar-1.30
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tar
CATEGORIES=		archivers perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Archive-Tar/
COMMENT=		Perl5 module interface to manipulate tar files

DEPENDS+=		p5-IO-Zlib>=1.01:../../devel/p5-IO-Zlib
DEPENDS+=		p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=		p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_PARAMS+=		"-d"	# Text::Diff is a prerequisite
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Archive/Tar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
