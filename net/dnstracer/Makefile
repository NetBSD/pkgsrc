# $NetBSD: Makefile,v 1.6 2005/11/03 17:19:47 tv Exp $

DISTNAME=		dnstracer-1.7
CATEGORIES=		net
MASTER_SITES=		http://www.mavetju.org/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.mavetju.org/unix/general.php
COMMENT=		Tool to trace dns queries

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PKG_OPTIONS_VAR=		PKG_OPTIONS.dnstracer
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"
