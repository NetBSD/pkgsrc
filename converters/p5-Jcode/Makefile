# $NetBSD: Makefile,v 1.4 2002/10/27 20:48:56 seb Exp $
#

DISTNAME=	Jcode-0.82
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5jco
CATEGORIES=	converters japanese
MASTER_SITES=	http://openlab.ring.gr.jp/Jcode/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://openlab.ring.gr.jp/Jcode/index.html
COMMENT=	perl5 module for handling various Japanese charsets

DEPENDS+=	p5-MIME-Base64>=2.1:../../converters/p5-MIME-Base64

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Jcode/.packlist

pre-configure:
	@cd ${WRKSRC}; ${RM} -f mac_install.pl win_install.pl

test:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} test

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
