# $NetBSD: Makefile,v 1.25 2012/10/03 21:57:13 wiz Exp $

DISTNAME=	wol-0.7.1
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ahh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ahh.sourceforge.net/wol/
COMMENT=	Small Wake On Lan client

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl pod2man
USE_PKGLOCALEDIR=	yes
INFO_FILES=		# PLIST

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
