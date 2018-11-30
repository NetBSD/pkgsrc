# $NetBSD: Makefile,v 1.45 2018/11/30 18:44:11 adam Exp $

DISTNAME=	dovecot-2.3-pigeonhole-0.5.4
PKGNAME=	${DISTNAME:S/-2.3-/-/}
CATEGORIES=	mail
MASTER_SITES=	http://pigeonhole.dovecot.org/releases/2.3/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.dovecot.org/
COMMENT=	Support for the Sieve language and the ManageSieve protocol
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config rpcgen
GNU_CONFIGURE=		yes

EGDIR=			${PREFIX}/share/examples/dovecot
CONFD=			${PKG_SYSCONFDIR}/dovecot/conf.d
MAKE_DIRS+=		${CONFD}
CONF_FILES+=		${EGDIR}/conf.d/20-managesieve.conf ${CONFD}/20-managesieve.conf
CONF_FILES+=		${EGDIR}/conf.d/90-sieve.conf ${CONFD}/90-sieve.conf

.include "../../mail/dovecot2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
