# $NetBSD: Makefile,v 1.2 2006/08/24 17:49:52 wiz Exp $

DISTNAME=	bootstrap-mk-files-20060824
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

CONFLICTS+=	mk-files-[0-9]*

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pkgsrc.org/
COMMENT=	*.mk files for the bootstrap bmake utility

NO_PKGTOOLS_REQD_CHECK=	# defined
PKG_PRESERVE=		# defined

NO_CHECKSUM=	yes
NO_MTREE=	yes
NO_BUILD=	yes

USE_TOOLS+=	sed

INSTALLTION_DIRS=	share/mk

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-configure:
	cd ${WRKSRC}; for file in bsd.* sys.mk; do			\
		${TEST} ! -f mods/${OPSYS}.$$file ||			\
		${CP} -f mods/${OPSYS}.$$file ${WRKSRC}/$$file;		\
	done
	cd ${WRKSRC};							\
	if ${TEST} -f mods/${OPSYS}.bsd.own.mk.in; then			\
		own_mk=mods/${OPSYS}.bsd.own.mk.in;			\
	else								\
		own_mk=mods/bsd.own.mk.in;				\
	fi;								\
	${SED}	-e 's|@ROOT_GROUP@|'${ROOT_GROUP}'|g'			\
		-e 's|@ROOT_USER@|'${ROOT_USER}'|g'			\
		-e 's|@SYSCONFDIR@|'${PKG_SYSCONFDIR}'|g'		\
		$$own_mk > bsd.own.mk

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/mk
	cd ${WRKSRC} && for file in bsd.* sys.mk; do			\
		${INSTALL_DATA} $$file ${PREFIX}/share/mk/$$file;	\
	done

.include "../../mk/bsd.pkg.mk"
