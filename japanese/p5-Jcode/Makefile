# $NetBSD: Makefile,v 1.11 2001/10/18 15:20:22 veego Exp $
#

DISTNAME=	Jcode-0.75
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5jco
CATEGORIES=	converters japanese
MASTER_SITES=	http://openlab.ring.gr.jp/Jcode/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://openlab.ring.gr.jp/Jcode/index.html
COMMENT=	perl5 module for handling various Japanese charsets

DEPENDS+=	p5-MIME-Base64>=2.1:../../converters/p5-MIME-Base64

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Jcode/.packlist

pre-configure:
	@cd ${WRKSRC}; ${RM} -f mac_install.pl win_install.pl

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

test:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} test

.include "../../mk/bsd.pkg.mk"
