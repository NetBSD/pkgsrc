# $NetBSD: Makefile,v 1.1.1.1 2004/08/06 15:05:54 jlam Exp $

DISTNAME=	amavisd-new-${VERSION}${PATCHLEVEL}
PKGNAME=	amavisd-new-${VERSION}${PATCHLEVEL:S/-//}
CATEGORIES=	security mail
MASTER_SITES=	http://www.ijs.si/software/amavisd/ \
		http://mirrors.catpipe.net/amavisd-new/ \
		http://ftp.cfu.net/pub/amavisd-new/ \
		ftp://ftp.cfu.net/pub/amavisd-new/

VERSION=	20040701
PATCHLEVEL=	# empty

MAINTAINER=	jdunn@aquezada.com
HOMEPAGE=	http://www.ijs.si/software/amavisd/
COMMENT=	daemonized interface between MTA and content checkers

DEPENDS+=	p5-Archive-Tar-[0-9]*:../../archivers/p5-Archive-Tar
DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-BerkeleyDB-[0-9]*:../../databases/p5-BerkeleyDB
DEPENDS+=	p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib
DEPENDS+=	p5-Convert-TNEF-[0-9]*:../../converters/p5-Convert-TNEF
DEPENDS+=	p5-Convert-UUlib-[0-9]*:../../converters/p5-Convert-UUlib
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-MIME-tools>=5.313:../../mail/p5-MIME-tools
DEPENDS+=	p5-Net-[0-9]*:../../net/p5-Net
DEPENDS+=	p5-Net-Server-[0-9]*:../../net/p5-Net-Server
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
DEPENDS+=	p5-Unix-Syslog-[0-9]*:../../sysutils/p5-Unix-Syslog

WRKSRC=		${WRKDIR}/amavisd-new-${VERSION}

CONFLICTS+=	amavis-[0-9]*
CONFLICTS+=	amavis-perl-[0-9]*

.include "../../mk/bsd.prefs.mk"

USE_PERL5=		yes
PERL5_REQD=		5.8.2
REPLACE_PERL+=		amavisd

USE_PKGINSTALL=		yes
AMAVIS_USER?=		vscan
AMAVIS_GROUP?=		vscan
AMAVIS_DIR?=		${VARBASE}/amavis
AMAVIS_QUARANTINE?=	${VARBASE}/virusmails
DOCDIR=			${PREFIX}/share/doc/amavisd-new
EGDIR=			${PREFIX}/share/examples/amavisd-new
MESSAGE_SRC=		${PKGDIR}/MESSAGE

BUILD_DEFS+=		AMAVIS_USER AMAVIS_GROUP AMAVIS_DIR AMAVIS_QUARANTINE
FILES_SUBST+=		AMAVIS_USER=${AMAVIS_USER}
FILES_SUBST+=		AMAVIS_GROUP=${AMAVIS_GROUP}
FILES_SUBST+=		AMAVIS_DIR=${AMAVIS_DIR}
FILES_SUBST+=		AMAVIS_QUARANTINE=${AMAVIS_QUARANTINE}

PKG_GROUPS=	${AMAVIS_GROUP}
PKG_USERS=	${AMAVIS_USER}:${AMAVIS_GROUP}::Virus\\ Scanning\\ Account:${AMAVIS_DIR}:${SH}
RCD_SCRIPTS=	amavisd
CONF_FILES=	${EGDIR}/amavisd.conf-minimal ${PKG_SYSCONFDIR}/amavisd.conf

# Global and legacy options
.if defined(USE_MILTER)
.  if !defined(PKG_OPTIONS.amavisd-new)
.    if defined(USE_MILTER) && !empty(USE_MILTER:M[Yy][Es][Ss])
PKG_OPTIONS.amavisd-new+=	milter
.    endif
.  endif
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.amavisd-new
PKG_SUPPORTED_OPTIONS=	milter
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmilter)
USE_BUILDLINK3= 	yes
GNU_CONFIGURE=  	yes
CONFIGURE_ARGS+=	--with-runtime-dir=${AMAVIS_DIR}
CONFIGURE_ARGS+=	--with-sockname=${AMAVIS_DIR}/amavisd.sock
CONFIGURE_ARGS+=	--with-user=${AMAVIS_USER}
CONFIGURE_ARGS+=	--with-milterinc=${BUILDLINK_PREFIX.libmilter}/include
CONFIGURE_ARGS+=	--with-milterlib=${BUILDLINK_PREFIX.libmilter}/lib
CONFIGURE_DIRS=		${WRKSRC}/helper-progs
BUILD_DIRS=		${WRKSRC}/helper-progs
RCD_SCRIPTS+=		amavismilter
MESSAGE_SRC+=		${PKGDIR}/MESSAGE.milter
PLIST_SUBST+=		MILTER=

PTHREAD_OPTS+=          require native	# doesn't work with pth
.  include "../../mail/libmilter/buildlink3.mk"
.  include "../../mk/pthread.buildlink3.mk"
.else
USE_LANGUAGES=		# empty
NO_BUILDLINK=		yes
NO_CONFIGURE=		yes
PLIST_SUBST+=		MILTER="@comment "

do-build:	replace-interpreter
.endif

SUBST_CLASSES+=		amavisd
SUBST_STAGE.amavisd=	pre-build
SUBST_FILES.amavisd=	${WRKSRC}/amavisd ${WRKSRC}/amavisd.conf
SUBST_SED.amavisd=	\
	-e "s|/etc/amavisd.conf|${PKG_SYSCONFDIR}/amavisd.conf|"	\
	-e "s|@AMAVIS_DIR@|${AMAVIS_DIR}|g"				\
	-e "s|@AMAVIS_USER@|${AMAVIS_USER}|g"				\
	-e "s|@AMAVIS_GROUP@|${AMAVIS_GROUP}|g"				\
	-e "s|@AMAVIS_QUARANTINE@|${AMAVIS_QUARANTINE}|g"		\
	-e "s|@LOCALBASE@|${LOCALBASE}|g"				\
	-e "s|@PREFIX@|${PREFIX}|g"

do-install:
.if !empty(PKG_OPTIONS:Mmilter)
	${INSTALL_PROGRAM} ${WRKSRC}/helper-progs/amavis ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/helper-progs/amavis-milter ${PREFIX}/sbin
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/amavisd ${PREFIX}/sbin/amavisd
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/AAAREADME.first ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LDAP.schema ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/MANIFEST ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES ${DOCDIR}
	for file in README_FILES/README.*; do				\
		${INSTALL_DATA} ${WRKSRC}/$$file ${DOCDIR};		\
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/amavisd.conf ${EGDIR}/amavisd.conf-minimal
	${INSTALL_DATA} ${WRKSRC}/amavisd.conf-default ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/amavisd.conf-sample ${EGDIR}

.include "../../mk/bsd.pkg.mk"
