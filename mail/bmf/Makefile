# $NetBSD: Makefile,v 1.10 2008/06/20 01:09:23 joerg Exp $
#

DISTNAME=	bmf-0.9.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bmf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/bmf/
COMMENT=	Self contained and extremely efficient Bayesian mail filter

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES

CONFIGURE_ARGS+=	--without-mysql
MAKE_ENV+=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
