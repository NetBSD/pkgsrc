# $NetBSD: Makefile,v 1.4 2005/12/05 20:50:46 rillig Exp $

DISTNAME=		gofish-1.1
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gofish/}

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://gofish.sourceforge.net/
COMMENT=		Gopher server

WRKSRC=			${WRKDIR}/gofish
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} \
			--localstatedir=${VARBASE}

EGDIR=			${PREFIX}/share/examples/gofish
RUNTIMEDIR=     	${VARBASE}/gopher

GOPHER_USER=    	gopher
GOPHER_GROUP=   	gopher
GOPHER_UID=		30
GOPHER_GID=		30
PKG_GROUPS=     	${GOPHER_GROUP}:${GOPHER_GID}
PKG_USERS=      	${GOPHER_USER}:${GOPHER_GROUP}:${GOPHER_UID}
OWN_DIRS_PERMS= 	${RUNTIMEDIR} ${GOPHER_USER} ${GOPHER_GROUP} 0750

RCD_SCRIPTS=		gopherd

CONF_FILES=	${EGDIR}/gofish.conf ${PKG_SYSCONFDIR}/gofish.conf \
		${EGDIR}/gofish-www.conf ${PKG_SYSCONFDIR}/gofish-www.conf

FILES_SUBST+=   	RUNTIMEDIR=${RUNTIMEDIR:Q}
FILES_SUBST+=		PKG_USERS=${PKG_USERS:Q}

post-configure:
	${MV} ${WRKSRC}/gofish.conf ${WRKSRC}/gofish.conf.orig
	${SED}	-e "s/;uid = -1/uid = ${GOPHER_UID}/g"	\
		-e "s/;gid = -1/gid = ${GOPHER_GID}/g"  \
		${WRKSRC}/gofish.conf.orig		\
		> ${WRKSRC}/gofish.conf


post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gofish
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gofish
	${INSTALL_DATA} ${WRKSRC}/gofish.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/gofish-www.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/Configure_GoFish ${PREFIX}/share/doc/gofish

.include "../../mk/bsd.pkg.mk"
