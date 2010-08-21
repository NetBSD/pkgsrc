# $NetBSD: Makefile,v 1.3 2010/08/21 16:33:14 seb Exp $
#

DISTNAME=	B-Hooks-OP-PPAddr-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=B/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/B-Hooks-OP-PPAddr/
COMMENT=	Hook into opcode execution
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-ExtUtils-Depends>=0.302:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-parent>0:../../devel/p5-parent

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/B/Hooks/OP/PPAddr/.packlist

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/hook_op_ppaddr.h ${DESTDIR}/${PREFIX}/include

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
