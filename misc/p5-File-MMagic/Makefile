# $NetBSD: Makefile,v 1.1.1.1 2000/11/27 02:23:30 kei Exp $

DISTNAME=		File-MMagic-1.09
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		kei@netbsd.org
HOMEPAGE=		http://www.daionet.gr.jp/~knok/

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/MMagic/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
