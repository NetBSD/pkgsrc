# $NetBSD: Makefile,v 1.2 2000/08/27 07:11:13 jlam Exp $
#

DISTNAME=	nkf-1.7
PKGNAME=	p5-nkf-1.7
CATEGORIES=	japanese converters
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/cmd/nkf/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/NKF/.packlist

WRKSRC=		${WRKDIR}/${DISTNAME}/NKF

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
