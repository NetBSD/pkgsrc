# $NetBSD: Makefile,v 1.16 2008/06/12 02:14:44 joerg Exp $
#

DISTNAME=	aide-0.6
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cs.tut.fi/pub/src/gnu/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	Older intrusion detection system for checking file integrity

PKG_DESTDIR_SUPPORT=	user-destdir

#BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	yes
USE_TOOLS+=	bison flex

.include "../../mk/bsd.pkg.mk"
