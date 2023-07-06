# $NetBSD: Makefile,v 1.31 2023/07/06 09:38:39 wiz Exp $

DISTNAME=	B-Utils-0.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=B/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/B-Utils
COMMENT=	Perl 5 module providing op tree manipulation helper functions
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
TOOL_DEPENDS+=	p5-ExtUtils-Depends>=0.302:../../devel/p5-ExtUtils-Depends

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/B/Utils/.packlist

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/BUtils.h ${DESTDIR}/${PREFIX}/include

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
