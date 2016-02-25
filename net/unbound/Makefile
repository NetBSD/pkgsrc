# $NetBSD: Makefile,v 1.42 2016/02/25 16:55:14 roy Exp $

DISTNAME=	unbound-1.5.7
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.unbound.net/downloads/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.unbound.net/
COMMENT=	DNS resolver and recursive server
LICENSE=	modified-bsd

BUILD_DEFS+=	VARBASE UNBOUND_USER UNBOUND_GROUP
FILES_SUBST+=	UNBOUND_USER=${UNBOUND_USER} UNBOUND_GROUP=${UNBOUND_GROUP}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-libexpat=${BUILDLINK_PREFIX.expat}
CONFIGURE_ARGS+=	--with-pidfile=${VARBASE}/run/unbound/unbound.pid
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--enable-allsymbols

# unbound uses some OpenBSD libc functions such as reallocarray(3)
# the existing tests just look for the symbol in libc regardless
# of any
CPPFLAGS+=		-D_OPENBSD_SOURCE

# Add the same logic as for ldns, so sha2/gost is configured automatically
CHECK_BUILTIN.openssl=	yes
.include "../../security/openssl/builtin.mk"
CHECK_BUILTIN.openssl=	no
.include "../../security/openssl/buildlink3.mk"

PLIST_VARS+=            sha2 gost
.if defined(USE_BUILTIN.openssl) && !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
PLIST_VARS.gost!=       \
        if ${PKG_ADMIN} pmatch 'openssl>=1.0.0' ${BUILTIN_PKG.openssl:Q}; then \
                ${ECHO} "yes";                                          \
        else                                                            \
                ${ECHO} "no";                                           \
        fi
PLIST_VARS.sha2!=       \
        if ${PKG_ADMIN} pmatch 'openssl>=0.9.8' ${BUILTIN_PKG.openssl:Q}; then \
                ${ECHO} "yes";                                          \
        else                                                            \
                ${ECHO} "no";                                           \
        fi
.else
PLIST_VARS.gost!=       \
        if ${PKG_INFO} -qe 'openssl>=1.0.0'; then                       \
                ${ECHO} yes;                                            \
        else                                                            \
                ${ECHO} no;                                             \
        fi
PLIST_VARS.sha2!=       \
        if ${PKG_INFO} -qe 'openssl>=0.9.8'; then                       \
                ${ECHO} yes;                                            \
        else                                                            \
                ${ECHO} no;                                             \
        fi
.endif
.if ${PLIST_VARS.gost} == "yes"
CONFIGURE_ARGS+=        --enable-gost
.else
CONFIGURE_ARGS+=        --disable-gost
.endif
.if ${PLIST_VARS.sha2} == "yes"
CONFIGURE_ARGS+=        --enable-sha2
.else
CONFIGURE_ARGS+=        --disable-sha2
.endif

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-configure
SUBST_MESSAGE.paths=	Fixing path names
SUBST_FILES.paths=	doc/example.conf doc/*.5 doc/*.8
SUBST_SED.paths=	-e "s|/usr/local|${PREFIX}|"

INSTALL_MAKE_FLAGS+=	\
    configfile=${PREFIX}/share/examples/unbound/unbound.conf

PKG_SYSCONFSUBDIR=	unbound

CONF_FILES+=	share/examples/unbound/unbound.conf \
	${PKG_SYSCONFDIR}/unbound.conf

RCD_SCRIPTS=	unbound
SMF_METHODS=	unbound
SMF_NAME=	unbound

UNBOUND_USER?=	unbound
UNBOUND_GROUP?=	unbound

PKG_GROUPS=	${UNBOUND_GROUP}
PKG_USERS=	${UNBOUND_USER}:${UNBOUND_GROUP}

.include "options.mk"

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
