# $NetBSD: Makefile,v 1.7 2011/11/21 08:13:08 ghen Exp $

DISTNAME=	dovecot-2.0-pigeonhole-0.2.5
PKGNAME=	${DISTNAME:S/-2.0-/-/}
CATEGORIES=	mail
MASTER_SITES=	http://www.rename-it.nl/dovecot/2.0/

MAINTAINER=	ghen@NetBSD.org
HOMEPAGE=	http://www.dovecot.org/
COMMENT=	Support for the Sieve language and the ManageSieve protocol
LICENSE=	gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

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
