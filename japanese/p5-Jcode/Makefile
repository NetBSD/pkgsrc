# $NetBSD: Makefile,v 1.1.1.1 2001/01/06 16:30:26 taca Exp $
#

DISTNAME=	Jcode-0.68
PKGNAME=	p5-Jcode-0.68
CATEGORIES=	converters japanese
MASTER_SITES=	http://openlab.ring.gr.jp/Jcode/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://openlab.ring.gr.jp/Jcode/index.html

DEPENDS+=	p5-MIME-Base64>=2.1:../../converters/p5-MIME-Base64

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Jcode/.packlist

post-extract:
	@cd ${WRKSRC}; ${RM} -f mac_install.pl win_install.pl

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
