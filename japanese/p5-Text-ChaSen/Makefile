# $NetBSD: Makefile,v 1.6 2001/10/18 15:20:23 veego Exp $

DISTNAME=		Text-ChaSen-1.03
PKGNAME=		p5-${DISTNAME}nb1
SVR4_PKGNAME=		p5tcs
CATEGORIES=		japanese perl5
MASTER_SITES=		http://www.daionet.gr.jp/~knok/chasen/

PATCHFILES=		ChaSen.pm-1.03-pod-fix.diff
PATCH_SITES=		http://www.daionet.gr.jp/~knok/chasen/

MAINTAINER=		kei@netbsd.org
HOMEPAGE=		http://www.daionet.gr.jp/~knok/chasen/
COMMENT=		perl5 module to use ChaSen

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/ChaSen/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../japanese/chasen/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
