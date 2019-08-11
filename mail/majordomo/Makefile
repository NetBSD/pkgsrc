# $NetBSD: Makefile,v 1.56 2019/08/11 13:21:29 wiz Exp $

DISTNAME=		majordomo-1.94.5
PKGREVISION=		24
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.sgi.com/other/majordomo/1.94.5/
MASTER_SITES+=		ftp://ftp-europe.sgi.com/other/majordomo/1.94.5/
EXTRACT_SUFX=		.tgz

MAINTAINER=		spz@NetBSD.org
HOMEPAGE=		https://www.greatcircle.com/majordomo/
COMMENT=		The Majordomo mailing list manager

LICENSE=		majordomo-license

PKG_DESTDIR_SUPPORT=	destdir
MAKE_JOBS_SAFE=		NO

RESTRICTED=		No distribution of modified binary packages to the general public
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

CONFLICTS+=		bounce-[0-9]*

USE_TOOLS+=		perl:run

BUILD_TARGET=		wrapper
INSTALL_TARGET=		install install-wrapper
MAKE_FILE=		Makefile.netbsd

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	majordomo
CONF_FILES+=		${EXAMPLEDIR}/aliases.majordomo ${PKG_SYSCONFDIR}/aliases
CONF_FILES+=		${EXAMPLEDIR}/majordomo.cf ${MAJORDOMO_CF}

MAJORDOMO_HOMEDIR?=	${VARBASE}/majordomo
MAJORDOMO_TMPDIR?=	${VARBASE}/majordomo/tmp
MAJORDOMO_CF?=		${PKG_SYSCONFDIR}/majordomo.cf
MAJORDOMO_USER?=	majordom
MAJORDOMO_GROUP?=	majordom

PKG_GECOS.${MAJORDOMO_USER}=	Majordomo Mailinglist Manager
PKG_HOME.${MAJORDOMO_USER}=	${MAJORDOMO_HOMEDIR}

PKG_GROUPS_VARS+=	MAJORDOMO_GROUP
PKG_USERS_VARS+=	MAJORDOMO_USER

MESSAGE_SUBST+=		HOME=${MAJORDOMO_HOMEDIR}			\
			MAJORDOMO_CF=${MAJORDOMO_CF}		\
			MAJORDOMO_USER=${MAJORDOMO_USER}		\
			MAJORDOMO_GROUP=${MAJORDOMO_GROUP}

DOCDIR=			${PREFIX}/share/doc/majordomo
DOCFILES=		Changelog FUTURE INSTALL LICENSE NEWLIST README
DOCDOCFILES=		FAQ README.sequencer list-owner-info \
			majordomo-faq.html majordomo.lisa6.ps majordomo.ora

EXAMPLEDIR=		${PREFIX}/share/examples/majordomo
EXDIRS=			archives archives/example-l digests \
			digests/example-l-digest lists
EXFILES=		example-l.passwd example-l.info
EXLISTS=		example-l example-l-digest

BUILD_DEFS+=		MAJORDOMO_TMPDIR
BUILD_DEFS+=		MAJORDOMO_HOMEDIR
BUILD_DEFS+=		MAJORDOMO_CF
BUILD_DEFS+=		VARBASE

USERGROUP_PHASE=	configure
PKG_GROUPS=		${MAJORDOMO_GROUP}
PKG_USERS=		${MAJORDOMO_USER}:${MAJORDOMO_GROUP}
OWN_DIRS_PERMS+=	${MAJORDOMO_HOMEDIR}		\
			${MAJORDOMO_USER} ${MAJORDOMO_GROUP} 0755
OWN_DIRS_PERMS+=	${MAJORDOMO_HOMEDIR}/archives	\
			${MAJORDOMO_USER} ${MAJORDOMO_GROUP} 0755
OWN_DIRS_PERMS+=	${MAJORDOMO_HOMEDIR}/digests	\
			${MAJORDOMO_USER} ${MAJORDOMO_GROUP} 0755
OWN_DIRS_PERMS+=	${MAJORDOMO_HOMEDIR}/lists	\
			${MAJORDOMO_USER} ${MAJORDOMO_GROUP} 0755
OWN_DIRS_PERMS+=	${MAJORDOMO_TMPDIR}		\
			${MAJORDOMO_USER} ${MAJORDOMO_GROUP} 0755

CONFIGURE_SED=		-e "s|@PREFIX@|${PREFIX}|g"			\
			-e "s|@PERL@|${PERL5}|g"			\
			-e "s|@HOME@|${MAJORDOMO_HOMEDIR}|g"		\
			-e "s|@MAJORDOMO_CF@|${MAJORDOMO_CF}|g"		\
			-e "s|@MAJORDOMO_USER@|${MAJORDOMO_USER}|g"	\
			-e "s|@MAJORDOMO_GROUP@|${MAJORDOMO_GROUP}|g"	\
			-e "s|@TMPDIR@|${MAJORDOMO_TMPDIR}|g"

MESSAGE_SED=		-e 's|$${PREFIX}|${PREFIX}|g'			\
			-e 's|$${HOME}|${HOME}|g'			\
			-e 's|$${MAJORDOMO_CF}|${MAJORDOMO_CF}|g'	\
			-e 's|$${MAJORDOMO_USER}|${MAJORDOMO_USER}|g'	\
			-e 's|$${MAJORDOMO_GROUP}|${MAJORDOMO_GROUP}|g'

MAKE_DIRS+=		${PKG_SYSCONFDIR}

INSTALLATION_DIRS+=	${PREFIX}/bin
INSTALLATION_DIRS+=	${PREFIX}/libexec/majordomo
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKGMANDIR}/man8

do-configure:
	${SED} ${CONFIGURE_SED} ${WRKSRC}/Makefile > ${WRKSRC}/Makefile.netbsd

post-build:
	${SED} ${CONFIGURE_SED} ${WRKSRC}/sample.cf > ${WRKSRC}/majordomo.cf
	${SED} ${CONFIGURE_SED} ${FILESDIR}/aliases.majordomo		\
		> ${WRKSRC}/aliases.majordomo
	${SED}	-e 's|$${PREFIX}|${PREFIX}|g'				\
		-e 's|$${HOME}|${HOME}|g'				\
		-e 's|$${MAJORDOMO_CF}|${MAJORDOMO_CF}|g'		\
		-e 's|$${MAJORDOMO_USER}|${MAJORDOMO_USER}|g'		\
		-e 's|$${MAJORDOMO_GROUP}|${MAJORDOMO_GROUP}|g'		\
		${PKGDIR}/MESSAGE > ${WRKSRC}/post-install-notes

post-install:
	${LN} -sf archive2.pl ${DESTDIR}${PREFIX}/libexec/majordomo/archive
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${DOCDIR}/${file}
.endfor
.for file in ${DOCDOCFILES}
	${INSTALL_DATA} ${WRKSRC}/Doc/${file} ${DESTDIR}${DOCDIR}/${file}
.endfor
	${INSTALL_DATA} ${WRKSRC}/post-install-notes ${DESTDIR}${DOCDIR}/post-install-notes
	${INSTALL} -d -m 755 -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} ${DESTDIR}${EXAMPLEDIR}
.for dir in ${EXDIRS}
	${INSTALL} -d -m 755 -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} ${DESTDIR}${EXAMPLEDIR}/${dir}
.endfor
	${INSTALL_DATA} ${WRKSRC}/aliases.majordomo \
		${DESTDIR}${EXAMPLEDIR}/aliases.majordomo
	${INSTALL} -m 644 -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} \
		${FILESDIR}/keep_me ${DESTDIR}${EXAMPLEDIR}/archives/example-l/.keep_me
	${INSTALL} -m 644 -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} \
		${FILESDIR}/keep_me ${DESTDIR}${EXAMPLEDIR}/digests/example-l-digest/.keep_me
.for file in ${EXFILES}
	${INSTALL} -m 644 -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} \
		${FILESDIR}/${file} ${DESTDIR}${EXAMPLEDIR}/lists/${file}
.endfor
.for file in ${EXLISTS}
	${INSTALL} -m 644 -o ${MAJORDOMO_USER} -g ${MAJORDOMO_GROUP} \
		/dev/null ${DESTDIR}${EXAMPLEDIR}/lists/${file}
.endfor
	${LN} -sf example-l.info ${DESTDIR}${EXAMPLEDIR}/lists/example-l-digest.info
	${LN} -sf example-l.passwd ${DESTDIR}${EXAMPLEDIR}/lists/example-l-digest.passwd
	${INSTALL_DATA} ${WRKSRC}/majordomo.cf \
		${DESTDIR}${EXAMPLEDIR}/majordomo.cf

# verify installation; requires interaction
test: install
	${DESTDIR}${PREFIX}/libexec/majordomo/wrapper config-test

.include "../../mk/bsd.pkg.mk"
