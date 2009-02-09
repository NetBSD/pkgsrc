# $NetBSD: Makefile,v 1.20 2009/02/09 22:56:26 joerg Exp $
#

DISTNAME=	fsh-1.2
PKGREVISION=	3
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/unix/fsh/ \
		http://www.lysator.liu.se/fsh/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lysator.liu.se/fsh/
COMMENT=	Fast remote command execution

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
INFO_FILES=	# PLIST

CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
