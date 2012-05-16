# $NetBSD: Makefile,v 1.1.1.1 2012/05/16 15:58:12 bouyer Exp $

DISTNAME=	Unicode-LineBreak-2012.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NE/NEZUMI/}

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Text::LineFold, Unicode::GCString and Unicode::LineBreak
HOMEPAGE=	http://search.cpan.org/~nezumi/Unicode-LineBreak-2012.02/
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_PARAMS+=	--with-bundled-sombok
MAKE_PARAMS+=	--disable-libthai

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/Unicode/LineBreak/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
