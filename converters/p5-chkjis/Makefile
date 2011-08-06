# $NetBSD: Makefile,v 1.15 2011/08/06 13:29:43 adam Exp $

DISTNAME=	chkjis
PKGNAME=	p5-chkjis-${VERSION}
PKGREVISION=	5
CATEGORIES=	japanese converters perl5
MASTER_SITES=	http://www2d.biglobe.ne.jp/~msyk/software/perl5/
EXTRACT_SUFX=	.pl

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www2d.biglobe.ne.jp/~msyk/software/chkjis.html
COMMENT=	Filter library substituting vendor's own characters

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

VERSION=	0.18
DIST_SUBDIR=	chkjis-${VERSION}
WRKSRC=		${WRKDIR}
USE_TOOLS+=	perl:run

NO_BUILD=		yes
NO_CONFIGURE=		yes
PERL5_CONFIGURE=	no

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PERL5_INSTALLVENDORLIB}
	${INSTALL_SCRIPT} ${WRKSRC}/chkjis.pl \
		${DESTDIR}${PERL5_INSTALLVENDORLIB}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
