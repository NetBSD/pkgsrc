# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 19:02:37 jlam Exp $

DISTNAME=		Text-Kakasi-1.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tka
CATEGORIES=		japanese textproc
MASTER_SITES=		http://www.daionet.gr.jp/~knok/kakasi/

MAINTAINER=		kei@netbsd.org
HOMEPAGE=		http://www.daionet.gr.jp/~knok/kakasi/
COMMENT=		perl5 module to use Kakasi

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Kakasi/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../textproc/kakasi/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
