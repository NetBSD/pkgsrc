# $NetBSD: Makefile,v 1.20 2020/01/18 23:32:49 rillig Exp $

DISTNAME=	rblcheck-1.5
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rblcheck/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rblcheck.sourceforge.net/
COMMENT=	Command-line interface to Paul Vixie's RBL filter
LICENSE=	gnu-gpl-v2

CONFLICTS=	udns-[0-9]*

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

DOCS=		README NEWS docs/rblcheck.ps

AUTO_MKDIRS=	yes

LDFLAGS.SunOS+=	-lnsl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rblcheck ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} &&						\
		${INSTALL_DATA} ${DOCS} ${DESTDIR}${PREFIX}/share/doc/rblcheck

.include "../../mk/bsd.pkg.mk"
