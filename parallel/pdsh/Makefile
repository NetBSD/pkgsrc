# $NetBSD: Makefile,v 1.3 2015/06/12 10:50:55 wiz Exp $
#

DISTNAME=	pdsh-2.29
PKGREVISION=	2
CATEGORIES=	parallel
MASTER_SITES=	http://pdsh.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://pdsh.googlecode.com/
COMMENT=	High-performance, parallel remote shell utility
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl:run

REPLACE_PERL+=		scripts/dshbak

CONFIGURE_ARGS+=	--with-ssh
CONFIGURE_ARGS+=	--with-dshgroups=${PKG_SYSCONFBASE}/dsh/group
CONFIGURE_ARGS+=	--with-machines=${PKG_SYSCONFDIR}/machines

PKG_SYSCONFSUBDIR=	${PKGBASE}

.include "../../mk/bsd.pkg.mk"
