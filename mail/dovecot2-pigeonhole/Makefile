# $NetBSD: Makefile,v 1.56 2020/03/15 22:52:45 adam Exp $

DISTNAME=	dovecot-2.3-pigeonhole-0.5.10
PKGNAME=	${DISTNAME:S/-2.3-/-/}
CATEGORIES=	mail
MASTER_SITES=	https://pigeonhole.dovecot.org/releases/2.3/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.dovecot.org/
COMMENT=	Support for the Sieve language and the ManageSieve protocol
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-hardening

EGDIR=			${PREFIX}/share/examples/dovecot
CONFD=			${PKG_SYSCONFDIR}/dovecot/conf.d
MAKE_DIRS+=		${CONFD}
CONF_FILES+=		${EGDIR}/conf.d/20-managesieve.conf ${CONFD}/20-managesieve.conf
CONF_FILES+=		${EGDIR}/conf.d/90-sieve.conf ${CONFD}/90-sieve.conf

.include "../../mail/dovecot2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
