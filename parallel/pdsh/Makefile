# $NetBSD: Makefile,v 1.6 2018/08/22 09:46:10 wiz Exp $
#

DISTNAME=	pdsh-2.31
PKGREVISION=	1
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=grondo/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/grondo/pdsh/
COMMENT=	High-performance, parallel remote shell utility
LICENSE=	gnu-gpl-v2

GITHUB_TAG=	${DISTNAME}

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
