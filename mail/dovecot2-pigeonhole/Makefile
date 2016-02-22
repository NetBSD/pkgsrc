# $NetBSD: Makefile,v 1.27 2016/02/22 12:41:01 taca Exp $

DISTNAME=	dovecot-2.2-pigeonhole-0.4.12
PKGNAME=	${DISTNAME:S/-2.2-/-/}
CATEGORIES=	mail
MASTER_SITES=	http://pigeonhole.dovecot.org/releases/2.2/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.dovecot.org/
COMMENT=	Support for the Sieve language and the ManageSieve protocol
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		pkg-config rpcgen
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

EGDIR=			${PREFIX}/share/examples/dovecot
CONFD=			${PKG_SYSCONFDIR}/dovecot/conf.d
MAKE_DIRS+=		${CONFD}
CONF_FILES+=		${EGDIR}/conf.d/20-managesieve.conf ${CONFD}/20-managesieve.conf
CONF_FILES+=		${EGDIR}/conf.d/90-sieve.conf ${CONFD}/90-sieve.conf

.include "../../mail/dovecot2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
