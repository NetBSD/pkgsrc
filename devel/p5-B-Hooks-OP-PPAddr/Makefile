# $NetBSD: Makefile,v 1.20 2021/05/24 19:50:09 wiz Exp $

DISTNAME=	B-Hooks-OP-PPAddr-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=B/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/B-Hooks-OP-PPAddr
COMMENT=	Hook into opcode execution
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-ExtUtils-Depends>=0.302:../../devel/p5-ExtUtils-Depends

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/B/Hooks/OP/PPAddr/.packlist

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/hook_op_ppaddr.h ${DESTDIR}/${PREFIX}/include

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
