# $NetBSD: Makefile,v 1.1.1.1 2000/11/27 07:27:53 kei Exp $

DISTNAME=		Text-ChaSen-1.03
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		japanese perl5
MASTER_SITES=		http://www.daionet.gr.jp/~knok/chasen/

MAINTAINER=		kei@netbsd.org
HOMEPAGE=		http://www.daionet.gr.jp/~knok/chasen/

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/ChaSen/.packlist
DEPENDS+=		chasen-2.0b6:../../japanese/chasen

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
