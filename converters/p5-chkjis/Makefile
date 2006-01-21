# $NetBSD: Makefile,v 1.11 2006/01/21 18:57:40 jlam Exp $
#

DISTNAME=	chkjis
PKGNAME=	p5-chkjis-${VERSION}
PKGREVISION=	2
CATEGORIES=	japanese converters perl5
MASTER_SITES=	http://www2d.biglobe.ne.jp/~msyk/software/perl5/
EXTRACT_SUFX=	.pl

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www2d.biglobe.ne.jp/~msyk/software/chkjis.html
COMMENT=	Filter library substituting vendor's own characters

WRKSRC=		${WRKDIR}

VERSION=	0.18
DIST_SUBDIR=	chkjis-${VERSION}
WRKSRC=		${WRKDIR}
USE_TOOLS+=	perl:run

NO_BUILD=		yes
NO_CONFIGURE=		yes
PERL5_CONFIGURE=	no

do-install:
	${INSTALL_DATA_DIR} ${PERL5_INSTALLVENDORLIB}
	${INSTALL_SCRIPT} ${WRKSRC}/chkjis.pl ${PERL5_INSTALLVENDORLIB}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
