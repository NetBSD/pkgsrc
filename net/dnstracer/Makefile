# $NetBSD: Makefile,v 1.8 2008/06/12 02:14:39 joerg Exp $

DISTNAME=		dnstracer-1.7
CATEGORIES=		net
MASTER_SITES=		http://www.mavetju.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mavetju.org/unix/general.php
COMMENT=		Tool to trace dns queries

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PKG_OPTIONS_VAR=		PKG_OPTIONS.dnstracer
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"
