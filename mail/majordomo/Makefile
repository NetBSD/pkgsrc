# $NetBSD: Makefile,v 1.21 2005/12/05 20:50:33 rillig Exp $

DISTNAME=		majordomo-1.94.5
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.sgi.com/other/majordomo/1.94.5/ \
			ftp://ftp-europe.sgi.com/other/majordomo/1.94.5/
EXTRACT_SUFX=   	.tgz

MAINTAINER=		packages@biology.nmsu.edu
HOMEPAGE=		http://www.greatcircle.com/majordomo/
COMMENT=		The Majordomo mailing list manager

LICENSE=		majordomo-license

.if exists(/usr/sbin/user)
ADDUSER=		/usr/sbin/useradd
ADDGROUP=		/usr/sbin/groupadd
.else
DEPENDS+=		user>=20000313:../../sysutils/user
ADDUSER=		${LOCALBASE}/sbin/useradd
ADDGROUP=		${LOCALBASE}/sbin/groupadd
.endif

USE_TOOLS+=		perl:run

NO_BIN_ON_FTP=		requires compiled-in hardcoded uid/gid
NO_BIN_ON_CDROM=	${NO_BIN_ON_FTP}

BUILD_TARGET=		wrapper
INSTALL_TARGET=		install install-wrapper

INSTALL_FILE=		${WRKDIR}/INSTALL
DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
MAKEFILE=		Makefile.netbsd

MAJORDOMO_TMPDIR?=	/var/tmp
MAJORDOMO_HOMEDIR?=	/home
MAJORDOMO_USER?=	majordom
MAJORDOMO_GROUP?=	majordom

PLIST_SUBST+=		HOME=${MAJORDOMO_HOMEDIR:Q}		\
			MAJORDOMO_USER=${MAJORDOMO_USER:Q}
MESSAGE_SUBST+=		HOME=${MAJORDOMO_HOMEDIR}		\
			MAJORDOMO_USER=${MAJORDOMO_USER}	\
			MAJORDOMO_GROUP=${MAJORDOMO_GROUP}

DOCDIR=			${PREFIX}/share/doc/majordomo
DOCFILES=		Changelog FUTURE INSTALL LICENSE NEWLIST README
DOCDOCFILES=		FAQ README.sequencer list-owner-info \
			majordomo-faq.html majordomo.lisa6.ps majordomo.ora

EXDIR=			${PREFIX}/share/examples/majordomo
EXDIRS=			archives archives/example-l digests \
			digests/example-l-digest lists
EXFILES=		example-l.passwd example-l.info
EXLISTS=		example-l example-l-digest

BUILD_DEFS+=		MAJORDOMO_USER MAJORDOMO_GROUP MAJORDOMO_TMPDIR

require-uid:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if ! ${ID} ${MAJORDOMO_USER} >/dev/null 2>&1; then		\
		${TOUCH} "/tmp/grouptestmajordomo1.$$";			\
		if ! ${CHGRP} ${MAJORDOMO_GROUP}			\
			"/tmp/grouptestmajordomo1.$$" >/dev/null 2>&1; then \
			realtarget="root-require-uid";			\
			action="create user for";			\
			${_SU_TARGET};					\
		fi;							\
		${RM} -f "/tmp/grouptestmajordomo1.$$";			\
	fi

root-require-uid:
	@${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

do-configure:
	@${SED} \
		-e 's|@MAJORDOMO_USER@|${MAJORDOMO_USER}|g' \
		-e 's|@MAJORDOMO_GROUP@|${MAJORDOMO_GROUP}|g' \
		-e 's|@HOME@|${MAJORDOMO_HOMEDIR}|g' \
		-e 's|@ADDUSER@|${ADDUSER}|g' \
		-e 's|@ADDGROUP@|${ADDGROUP}|g' \
		-e 's|@CHGRP@|${CHGRP}|g' \
		-e 's|@ID@|${ID}|g' \
		-e 's|@TOUCH@|${TOUCH}|g' \
		-e 's|@RM@|${RM}|g' \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	@${SED} \
		-e 's|@MAJORDOMO_USER@|${MAJORDOMO_USER}|g' \
		-e 's|@MAJORDOMO_GROUP@|${MAJORDOMO_GROUP}|g' \
		-e 's|@HOME@|${MAJORDOMO_HOMEDIR}|g' \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
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
# for safety's sake, if the user/group got deleted since configuration
	@${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	@${LN} -sf archive2.pl ${PREFIX}/libexec/majordomo/archive
	${INSTALL_DATA_DIR} ${DOCDIR}
.for file in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCDIR}/${file}
.endfor
.for file in ${DOCDOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/Doc/${file} ${DOCDIR}/${file}
.endfor
	@${INSTALL_DATA} ${MESSAGE} ${DOCDIR}/post-install-notes
	${INSTALL} -d -m 775 -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} ${EXDIR}
.for dir in ${EXDIRS}
	@${INSTALL} -d -m 775 -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} ${EXDIR}/${dir}
.endfor
	@${INSTALL_DATA} -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} \
		${WRKSRC}/aliases.majordomo ${EXDIR}/aliases.majordomo
	@${INSTALL_DATA} -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} \
		${FILESDIR}/keep_me ${EXDIR}/archives/example-l/.keep_me
	@${INSTALL_DATA} -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} \
		${FILESDIR}/keep_me ${EXDIR}/digests/example-l-digest/.keep_me
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
test: install
	${PREFIX}/libexec/majordomo/wrapper config-test

.include "../../mk/bsd.pkg.mk"
