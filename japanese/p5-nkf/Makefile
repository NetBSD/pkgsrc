# $NetBSD: Makefile,v 1.1.1.1 1999/10/11 06:23:43 sakamoto Exp $
#

DISTNAME=	nkf-1.7
PKGNAME=	p5-nkf-1.7
CATEGORIES=	japanese converters
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/cmd/nkf/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org

USE_PERL5=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/NKF

do-configure:
	@cd ${WRKSRC} && perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
