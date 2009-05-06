# $NetBSD: Makefile,v 1.9 2009/05/06 03:44:02 snj Exp $

DISTNAME=	nslint-2.1a9
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/ \
		ftp://ftp.ee.lbl.gov/old/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ee.lbl.gov/ftp.html
COMMENT=	Perform consistency checks on DNS zone files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
BUILD_TARGET=	nslint
INSTALL_TARGET=	install install-man
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
