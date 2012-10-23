# $NetBSD: Makefile,v 1.10 2012/10/23 17:18:43 asau Exp $

DISTNAME=	nslint-2.1a9
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/ \
		ftp://ftp.ee.lbl.gov/old/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ee.lbl.gov/ftp.html
COMMENT=	Perform consistency checks on DNS zone files

GNU_CONFIGURE=	YES
BUILD_TARGET=	nslint
INSTALL_TARGET=	install install-man
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
