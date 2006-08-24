# $NetBSD: Makefile,v 1.2 2006/08/24 17:46:53 wiz Exp $

DISTNAME=	bootstrap-extra-files-20060824
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extra bootstrap files and scripts for ${OPSYS}

NO_CHECKSUM=	yes
NO_MTREE=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

OPSYSVARS+=		NEED_FAKELDD
NEED_FAKELDD.IRIX=	# empty
NEED_FAKELDD.*=		"@comment "
PLIST_SUBST+=		NEED_FAKELDD=${NEED_FAKELDD}

OPSYSVARS+=		NEED_MKDIR
NEED_MKDIR.UnixWare=	# empty
NEED_MKDIR.*=		"@comment "
PLIST_SUBST+=		NEED_MKDIR=${NEED_MKDIR}

OPSYSVARS+=		NEED_STRIP
NEED_STRIP.AIX=		# empty
NEED_STRIP.*=		"@comment "
PLIST_SUBST+=		NEED_STRIP=${NEED_STRIP}

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	if ${TEST} -z ${NEED_FAKELDD:M*:Q}""; then			\
		${INSTALL_SCRIPT_DIR} ${PREFIX}/sbin;			\
		${INSTALL_SCRIPT} ${WRKSRC}/fakeldd			\
			${PREFIX}/sbin/fakeldd;				\
	fi
	if ${TEST} -z ${NEED_MKDIR:M*:Q}""; then			\
		${INSTALL_SCRIPT_DIR} ${PREFIX}/bin;			\
		${INSTALL_SCRIPT} ${WRKSRC}/mkdir-sh			\
			${PREFIX}/bin/mkdir-sh;				\
	fi
	if ${TEST} -z ${NEED_STRIP:M*:Q}""; then			\
		${INSTALL_SCRIPT_DIR} ${PREFIX}/bin;			\
		${INSTALL_SCRIPT} ${WRKSRC}/strip-sh			\
			${PREFIX}/bin/strip;				\
	fi

.include "../../mk/bsd.pkg.mk"
