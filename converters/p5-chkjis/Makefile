# $NetBSD: Makefile,v 1.1.1.1 2004/11/25 15:17:52 taca Exp $
#

DISTNAME=	chkjis
PKGNAME=	p5-chkjis-0.18
CATEGORIES=	textproc
MASTER_SITES=	http://www2d.biglobe.ne.jp/~msyk/software/perl5/
EXTRACT_SUFX=	.pl

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www2d.biglobe.ne.jp/~msyk/software/chkjis.html
COMMENT=	Filter library substituting vendor's own characters

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	yes

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}

WRKSRC=		${WRKDIR}
USE_PERL5=	yes
NO_BUILD=	yes
NO_CONFIGURE=	yes
NO_WRAPPER=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/chkjis.pl ${PERL5_SITELIB}

.include "../../mk/bsd.pkg.mk"
