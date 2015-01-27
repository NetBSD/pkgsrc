# $NetBSD: Makefile,v 1.23 2015/01/27 22:03:16 gdt Exp $
#

DISTNAME=	coda-6.9.5
PKGREVISION=	8
CATEGORIES=	net
MASTER_SITES=	http://www.coda.cs.cmu.edu/pub/coda/src/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	Coda distributed fileystem

LICENSE=	gnu-gpl-v2

# This package requires a coda kernel module, which is only known to
# work on NetBSD and Linux.  It is known not to work on DragonFly (has
# never existed) and FreeBSD (removed).
ONLY_FOR_PLATFORM+=	NetBSD-*-* Linux-*-*

# See http://coda.wikidev.net/Quick_Client_Action for hints on how
# to configure venus.

PKG_SYSCONFSUBDIR=	coda

#SMF_INSTANCES=		TODO

EGDIR=			${PREFIX}/share/examples/coda
CONF_FILES+=		${EGDIR}/server.conf	${PKG_SYSCONFDIR}/server.conf
CONF_FILES+=		${EGDIR}/venus.conf	${PKG_SYSCONFDIR}/venus.conf
CONF_FILES+=		${EGDIR}/realms		${PKG_SYSCONFDIR}/realms

INSTALLATION_DIRS+=	${EGDIR}

USE_TOOLS+=		gmake pkg-config perl perl:run
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
REPLACE_PERL=		coda-src/scripts/tape.pl coda-src/scripts/volmunge

# Sources use both in equal share 
CFLAGS.SunOS+=		-Du_int32_t=uint32_t
CFLAGS.SunOS+=		-Du_int16_t=uint16_t
CFLAGS.SunOS+=		-Du_int8_t=uint8_t
# Use the value from <netdb.h>
CFLAGS.SunOS+=		-DMAXHOSTNAMELEN=256

post-install:
	${INSTALL_DATA} ${WRKSRC}/coda-src/vice/server.conf.ex \
		  ${DESTDIR}${EGDIR}/server.conf
	${INSTALL_DATA} ${WRKSRC}/coda-src/venus/venus.conf.ex \
		  ${DESTDIR}${EGDIR}/venus.conf
	${INSTALL_DATA} ${WRKSRC}/coda-src/venus/realms \
		  ${DESTDIR}${EGDIR}/realms

.include "../../devel/lwp/buildlink3.mk"
.include "../../devel/rpc2/buildlink3.mk"
.include "../../devel/rvm/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
