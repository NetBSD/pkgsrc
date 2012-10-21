# $NetBSD: Makefile,v 1.18 2012/10/21 17:37:03 cheusov Exp $

DISTNAME=	rblcheck-1.5
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rblcheck/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rblcheck.sourceforge.net/
COMMENT=	Command-line interface to Paul Vixie's RBL filter
LICENSE=	gnu-gpl-v2

CONFLICTS=	udns-[0-9]*

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

DOCS=		README NEWS docs/rblcheck.ps

AUTO_MKDIRS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rblcheck ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} &&						\
		${INSTALL_DATA} ${DOCS} ${DESTDIR}${PREFIX}/share/doc/rblcheck

.include "../../mk/bsd.pkg.mk"
