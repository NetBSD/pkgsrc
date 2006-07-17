# $NetBSD: Makefile,v 1.1.1.1 2006/07/17 14:21:31 jlam Exp $

DISTNAME=	bootstrap-extra-files-20060714
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	extra bootstrap files and scripts for ${OPSYS}

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
NEED_STRIP.UnixWare=	# empty
NEED_STRIP.*=		"@comment "
PLIST_SUBST+=		NEED_MKDIR=${NEED_MKDIR}

OPSYSVARS+=		NEED_STRIP
NEED_STRIP.AIX=		# empty
NEED_STRIP.*=		"@comment "
PLIST_SUBST+=		NEED_STRIP=${NEED_STRIP}

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	if ${TEST} -n ${NEED_FAKELDD:M*:Q}""; then			\
		${INSTALL_SCRIPT_DIR} ${PREFIX}/sbin;			\
		${INSTALL_SCRIPT} ${WRKSRC}/fakeldd			\
			${PREFIX}/sbin/fakeldd;				\
	fi
	if ${TEST} -n ${NEED_MKDIR:M*:Q}""; then			\
		${INSTALL_SCRIPT_DIR} ${PREFIX}/bin;			\
		${INSTALL_SCRIPT} ${WRKSRC}/mkdir-sh			\
			${PREFIX}/bin/mkdir-sh;				\
	fi
	if ${TEST} -n ${NEED_STRIP:M*:Q}""; then			\
		${INSTALL_SCRIPT_DIR} ${PREFIX}/bin;			\
		${INSTALL_SCRIPT} ${WRKSRC}/strip-sh			\
			${PREFIX}/bin/strip;				\
	fi

.include "../../mk/bsd.pkg.mk"
