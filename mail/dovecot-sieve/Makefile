# $NetBSD: Makefile,v 1.3.14.1 2009/09/16 10:54:23 tron Exp $

DISTNAME=		dovecot-sieve-1.1.7
CATEGORIES=		mail
MASTER_SITES=		http://www.dovecot.org/releases/sieve/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://wiki.dovecot.org/LDA/Sieve
COMMENT=		Sieve plugin for Dovecot

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--with-dovecot=${PREFIX}/lib/dovecot

.include "../../mail/dovecot/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
