# $NetBSD: Makefile,v 1.5 2001/05/15 23:49:06 taca Exp $
#

DISTNAME=	Jcode-0.70
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters japanese
MASTER_SITES=	http://openlab.ring.gr.jp/Jcode/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://openlab.ring.gr.jp/Jcode/index.html
COMMENT=	perl5 module for handling various Japanese charsets

DEPENDS+=	p5-MIME-Base64>=2.1:../../converters/p5-MIME-Base64

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Jcode/.packlist
ALL_TARGET=	all test

pre-configure:
	@cd ${WRKSRC}; ${RM} -f mac_install.pl win_install.pl

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
