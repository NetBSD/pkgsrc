# $NetBSD: Makefile,v 1.12 2022/06/28 11:35:24 wiz Exp $
#

DISTNAME=	pdsh-2.31
PKGREVISION=	5
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=grondo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
