# $NetBSD: Makefile,v 1.4 2001/10/18 15:20:25 veego Exp $
#

DISTNAME=	nkf-1.7
PKGNAME=	p5-nkf-1.7
SVR4_PKGNAME=	p5nkf
CATEGORIES=	japanese converters
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/cmd/nkf/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
COMMENT=	Perl library for Network Kanji code conversion Filter

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/NKF/.packlist

WRKSRC=		${WRKDIR}/${DISTNAME}/NKF

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
