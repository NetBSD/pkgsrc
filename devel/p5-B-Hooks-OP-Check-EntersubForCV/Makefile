# $NetBSD: Makefile,v 1.10 2017/06/05 14:22:37 ryoon Exp $

DISTNAME=	B-Hooks-OP-Check-EntersubForCV-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=B/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/B-Hooks-OP-Check-EntersubForCV/
COMMENT=	Invoke callbacks on construction of entersub OPs for certain CVs
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-ExtUtils-Depends-[0-9]*:../../devel/p5-ExtUtils-Depends
DEPENDS+=	p5-B-Utils>=0.19:../../devel/p5-B-Utils
# requires parent, Scalar::Util
PERL5_REQD+=	5.10.1

PERL5_MODULE_TYPE=	Module::Install::Bundled

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/B/Hooks/OP/Check/EntersubForCV/.packlist

BUILDLINK_DEPMETHOD.p5-B-Hooks-OP-Check=	full
BUILDLINK_API_DEPENDS.p5-B-Hooks-OP-Check+=	p5-B-Hooks-OP-Check>=0.19

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/hook_op_check_entersubforcv.h ${DESTDIR}/${PREFIX}/include

.include "../../devel/p5-B-Hooks-OP-Check/buildlink3.mk"
.include "../../devel/p5-B-Utils/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
