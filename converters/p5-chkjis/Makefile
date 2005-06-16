# $NetBSD: Makefile,v 1.6 2005/06/16 06:57:43 jlam Exp $
#

DISTNAME=	chkjis
PKGNAME=	p5-chkjis-${VERSION}
PKGREVISION=	1
CATEGORIES=	japanese converters perl5
MASTER_SITES=	http://www2d.biglobe.ne.jp/~msyk/software/perl5/
EXTRACT_SUFX=	.pl

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www2d.biglobe.ne.jp/~msyk/software/chkjis.html
COMMENT=	Filter library substituting vendor's own characters

WRKSRC=		${WRKDIR}

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}

VERSION=	0.18
DIST_SUBDIR=	chkjis-${VERSION}
WRKSRC=		${WRKDIR}
USE_PERL5=	yes
NO_BUILD=	yes
NO_CONFIGURE=	yes
NO_WRAPPER=	yes

do-install:
	${INSTALL_DATA_DIR} ${PERL5_SITELIB}
	${INSTALL_SCRIPT} ${WRKSRC}/chkjis.pl ${PERL5_SITELIB}

.include "../../mk/bsd.pkg.mk"
