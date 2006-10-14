# $NetBSD: Makefile,v 1.7 2006/10/14 02:01:33 rillig Exp $

DISTNAME=	libol-0.3.18
CATEGORIES=	sysutils
PKGREVISION=	1
MASTER_SITES=	http://www.balabit.com/downloads/libol/0.3/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE= 	http://www.balabit.com/products/syslog_ng/
COMMENT=	Support library for syslog-ng

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	scsh-[0-9]*:../../shells/scsh

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

.include "../../mk/bsd.pkg.mk"
