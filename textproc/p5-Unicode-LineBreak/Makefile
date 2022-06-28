# $NetBSD: Makefile,v 1.23 2022/06/28 11:36:38 wiz Exp $

DISTNAME=	Unicode-LineBreak-2019.001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	Text::LineFold, Unicode::GCString and Unicode::LineBreak
HOMEPAGE=	https://metacpan.org/release/Unicode-LineBreak
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MIME-Charset>=1.006.2:../../mail/p5-MIME-Charset

MAKE_PARAMS+=	--with-bundled-sombok
MAKE_PARAMS+=	--disable-libthai
MAKE_JOBS_SAFE=	no

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/Unicode/LineBreak/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
