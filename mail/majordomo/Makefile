# $NetBSD: Makefile,v 1.5 1999/08/18 08:46:53 agc Exp $

DISTNAME=		majordomo-1.94.4
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.sgi.com/other/majordomo/1.94.4/ \
			ftp://ftp-europe.sgi.com/other/majordomo/1.94.4/
EXTRACT_SUFX=   	.tgz

MAINTAINER=		packages@biology.nmsu.edu
HOMEPAGE=		http://www.greatcircle.com/majordomo/

DEPENDS+=		addnerd-1.6:../../sysutils/addnerd

USE_PERL5=		yes

NO_PACKAGE=		requires compiled in uid/gid

ALL_TARGET=		wrapper
INSTALL_TARGET=		install install-wrapper

PLIST_SRC=		${WRKDIR}/PLIST.tmp
MESSAGE_FILE=		${WRKDIR}/MESSAGE
REQ_FILE=		${WRKDIR}/REQ
MAKEFILE=		Makefile.netbsd

MAJORDOMO_TMPDIR?=	/var/tmp
MAJORDOMO_HOMEDIR?=	/home
MAJORDOMO_USER?=	majordom
MAJORDOMO_GROUP?=	majordom

DOCDIR=			${PREFIX}/share/doc/majordomo
DOCFILES=		Changelog FUTURE INSTALL LICENSE NEWLIST README
DOCDOCFILES=		FAQ README.sequencer list-owner-info majordomo-faq.html \
			majordomo.lisa6.ps majordomo.ora

EXDIR=			${PREFIX}/share/examples/majordomo
EXDIRS=			archives archives/example-l digests digests/example-l-digest lists
EXFILES=		example-l.passwd example-l.info
EXLISTS=		example-l example-l-digest

BUILD_DEFS+=		MAJORDOMO_USER MAJORDOMO_GROUP MAJORDOMO_TMPDIR

require-uid:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if finger ${MAJORDOMO_USER} 2>&1 | ${GREP} "Login: ${MAJORDOMO_USER}" >/dev/null && ${GREP} -s "^${MAJORDOMO_GROUP}\:" /etc/group 2>/dev/null 1>&2 ; \
	then \
	:; \
	else \
		${MAKE} ${.MAKEFLAGS} su-require-uid; \
	fi

su-require-uid:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ `${ID} -u` = 0 ]; then					\
		${MAKE} ${.MAKEFLAGS} root-require-uid;			\
	elif [ "X${BATCH}" != X"" ]; then				\
		${ECHO_MSG} "Warning: Batch mode, not superuser, can't create majordomo user."; \
		${ECHO_MSG} "Become root and try again."; \
	else								\
		make=`${TYPE} ${MAKE} | ${AWK} '{ print $$NF }'`;	\
		args="";						\
		if [ "X${PKG_DEBUG_LEVEL}" != X"" ]; then		\
			args="$$args PKG_DEBUG_LEVEL=${PKG_DEBUG_LEVEL}"; \
		fi;							\
		if [ "X${PRE_ROOT_CMD}" != "X${TRUE}" ]; then		\
			${ECHO} "*** WARNING *** Running: ${PRE_ROOT_CMD}"; \
			${PRE_ROOT_CMD};				\
		fi;                                             	\
		${ECHO_MSG} "===>  Becoming root@`/bin/hostname` to create majordomo user."; \
		${ECHO_MSG} -n "`${ECHO} ${SU_CMD} | ${AWK} '{ print $$1 }'` ";\
		${SU_CMD} "cd ${.CURDIR}; $$make $$args ${.MAKEFLAGS} root-require-uid"; \
	fi

root-require-uid:
	@${SH} ${REQ_FILE} ${PKGNAME} INSTALL

do-configure:
	@${SED} \
		-e 's|@MAJORDOMO_USER@|${MAJORDOMO_USER}|g' \
		-e 's|@MAJORDOMO_GROUP@|${MAJORDOMO_GROUP}|g' \
		-e 's|@HOME@|${MAJORDOMO_HOMEDIR}|g' \
		-e 's|@LOCALBASE@|${LOCALBASE}|g' \
		< ${PKGDIR}/REQ > ${REQ_FILE}
	@${MAKE} ${.MAKEFLAGS} require-uid
	@${SED} \
		-e 's:@PREFIX@:${PREFIX}:g' \
		-e 's:@LOCALBASE@:${LOCALBASE}:g' \
		-e 's|@HOME@|${MAJORDOMO_HOMEDIR}|g' \
		-e 's:@MAJORDOMO_USER@:${MAJORDOMO_USER}:g' \
		-e "s:@UID@:`${ID} -ru ${MAJORDOMO_USER}`:g" \
		-e "s:@GID@:`${ID} -rg ${MAJORDOMO_USER}`:g" \
		-e 's:@TMPDIR@:${MAJORDOMO_TMPDIR}:g' \
		< ${WRKSRC}/Makefile > ${WRKSRC}/Makefile.netbsd
	@${SED} \
		-e 's:@PREFIX@:${PREFIX}:g' \
		-e 's:@HOME@:${MAJORDOMO_HOMEDIR}:g' \
		-e 's:@MAJORDOMO_USER@:${MAJORDOMO_USER}:g' \
		-e 's:@TMPDIR@:${MAJORDOMO_TMPDIR}:g' \
		< ${WRKSRC}/sample.cf > ${WRKSRC}/majordomo.cf
	@${SED} \
		-e 's:@PREFIX@:${PREFIX}:g' \
		-e 's:@HOME@:${MAJORDOMO_HOMEDIR}:g' \
		-e 's:@MAJORDOMO_USER@:${MAJORDOMO_USER}:g' \
		< ${FILESDIR}/aliases.majordomo > ${WRKSRC}/aliases.majordomo

pre-install:
	@${SED}  \
		-e 's|@HOME@|${MAJORDOMO_HOMEDIR}|g' \
		-e 's|@MAJORDOMO_USER@|${MAJORDOMO_USER}|g' \
		< ${PKGDIR}/PLIST > ${PLIST_SRC}
	@${SED} \
		-e 's:@PREFIX@:${PREFIX}:g' \
		-e 's:@HOME@:${MAJORDOMO_HOMEDIR}:g' \
		-e 's:@MAJORDOMO_USER@:${MAJORDOMO_USER}:g' \
		-e 's:@MAJORDOMO_GROUP@:${MAJORDOMO_GROUP}:g' \
		< ${PKGDIR}/MESSAGE > ${MESSAGE_FILE}

post-install:
	@${LN} -sf archive2.pl ${PREFIX}/libexec/majordomo/archive
	${INSTALL_DATA_DIR} ${DOCDIR}
.for file in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCDIR}/${file}
.endfor
.for file in ${DOCDOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/Doc/${file} ${DOCDIR}/${file}
.endfor
	@${INSTALL_DATA} ${MESSAGE_FILE} ${DOCDIR}/post-install-notes
	${INSTALL} -d -m 775 -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} ${EXDIR}
.for dir in ${EXDIRS}
	@${INSTALL} -d -m 775 -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} ${EXDIR}/${dir}
.endfor
	@${INSTALL_DATA} -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} \
		${WRKSRC}/aliases.majordomo ${EXDIR}/aliases.majordomo
	@${INSTALL_DATA} -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} \
		${FILESDIR}/.keep_me ${EXDIR}/archives/example-l/.keep_me
	@${INSTALL_DATA} -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} \
		${FILESDIR}/.keep_me ${EXDIR}/digests/example-l-digest/.keep_me
.for file in ${EXFILES}
	@${INSTALL_DATA} -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} \
		${FILESDIR}/${file} ${EXDIR}/lists/${file}
.endfor
.for file in ${EXLISTS}
	@${INSTALL} -m 664 -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} \
		/dev/null ${EXDIR}/lists/${file}
.endfor
	@${LN} -sf example-l.info ${EXDIR}/lists/example-l-digest.info
	@${LN} -sf example-l.passwd ${EXDIR}/lists/example-l-digest.passwd
	${INSTALL_DATA} -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} \
		${WRKSRC}/majordomo.cf ${EXDIR}/majordomo.cf

# verify installation; requires interaction
check test: install
	${PREFIX}/libexec/majordomo/wrapper config-test

.include "../../mk/bsd.pkg.mk"
