# $NetBSD: Makefile,v 1.3 2004/12/04 01:49:17 wiz Exp $

DISTNAME=		solid-pop3d-0.15
CATEGORIES=		mail
MASTER_SITES=		http://solidpop3d.pld.org.pl/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://solidpop3d.pld.org.pl/
COMMENT=		Flexible POP3 server

EGDIR=			${PREFIX}/share/examples/spop3d
MESSAGE_SUBST+=		EGDIR=${EGDIR}

PLIST_SRC=
EXAMPLES=

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-logextend	\
			--enable-statistics

BUILD_DEFS+=		USE_INET6

.if defined(SPOP3D_ENABLE_APOP)
CONFIGURE_ARGS+=	--enable-apop
PLIST_SRC+=		${.CURDIR}/PLIST.apop
.endif

.if defined(SPOP3D_ENABLE_STANDALONE)
CONFIGURE_ARGS+=	--enable-standalone
CONFIGURE_ARGS+=	--enable-connect
.endif

.if defined(SPOP3D_ENABLE_ALIASES)
CONFIGURE_ARGS+=	--enable-mapping
CONFIGURE_ARGS+=	--enable-nonip
.endif

.if defined(USE_INET6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

EXAMPLES+=		config.example

PLIST_SRC+=		${.CURDIR}/PLIST

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/doc; for i in ${EXAMPLES}; do			\
		${INSTALL_DATA} $${i} ${EGDIR}/$${i};			\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/solid-pop3d
.for i in AUTHORS CONFIGFILE COPYING ChangeLog INSTALL README THANKS VIRTUALS
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/solid-pop3d
.endfor

.include "../../mk/bsd.pkg.mk"
