# $NetBSD: Makefile,v 1.7 2006/03/04 21:30:18 jlam Exp $

DISTNAME=		dnstracer-1.7
CATEGORIES=		net
MASTER_SITES=		http://www.mavetju.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mavetju.org/unix/general.php
COMMENT=		Tool to trace dns queries

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PKG_OPTIONS_VAR=		PKG_OPTIONS.dnstracer
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"
