# $NetBSD: Makefile,v 1.5 2022/08/18 23:33:23 tnn Exp $
#

DISTNAME=	cfourcc-0.1.3.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=mypapit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mypapit/cfourcc
COMMENT=	Command-line tool for changing AVI FourCC codes
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cfourcc \
	    ${DESTDIR}${PREFIX}/bin/cfourcc

.include "../../mk/bsd.pkg.mk"
