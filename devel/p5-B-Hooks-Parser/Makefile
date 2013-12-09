# $NetBSD: Makefile,v 1.9 2013/12/09 14:17:43 obache Exp $

DISTNAME=	B-Hooks-Parser-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=B/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/B-Hooks-Parser/
COMMENT=	Interface to perls parser variables
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.10.1,p5-parent>0}:../../devel/p5-parent

BUILD_DEPENDS+=	p5-B-Hooks-EndOfScope-[0-9]*:../../devel/p5-B-Hooks-EndOfScope
BUILD_DEPENDS+=	p5-ExtUtils-Depends-[0-9]*:../../devel/p5-ExtUtils-Depends

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/B/Hooks/Parser/.packlist

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/hook_parser.h ${DESTDIR}/${PREFIX}/include

.include "../../devel/p5-B-Hooks-OP-Check/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
