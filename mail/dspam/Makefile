# $NetBSD: Makefile,v 1.10 2004/10/03 00:12:52 tv Exp $

DISTNAME=	dspam-3.0.0
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	http://www.nuclearelephant.com/projects/dspam/sources/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.nuclearelephant.com/projects/dspam/
COMMENT=	Extremely scalable, statistical-hybrid anti-spam filter

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

USE_PERL5=		yes
REPLACE_PERL=		tools/dspam_genaliases.in			\
			tools/dspam_corpus.in				\
			cgi/admin.cgi cgi/admingraph.cgi		\
			cgi/dspam.cgi cgi/graph.cgi

PKGCONFIG_OVERRIDE+=	dspam.pc.in

SUBST_CLASSES=		cgi
SUBST_STAGE.cgi=	post-patch
SUBST_FILES.cgi=	cgi/dspam.cgi cgi/admin.cgi
SUBST_SED.cgi=		-e "s|/usr/local/bin/dspam|${PREFIX}/bin/dspam|g" \
			-e "s|/var/dspam|${DSPAM_HOME}|g"		\
			-e "s|/usr/local|${PREFIX}|g"			\
			-e "s|LARGE_SCLAE|LARGE_SCALE|g"		\
			-e "s|-deaf|${DSPAM_PSFLAGS}|g"
SUBST_MESSAGE.cgi=	"Fixing paths and typos."

BUILD_DEFS+=		DSPAM_HOME
BUILD_DEFS+=		DSPAM_SIGNATURE_LIFE
BUILD_DEFS+=		DSPAM_USER DSPAM_GROUP
BUILD_DEFS+=		DSPAM_BINMODE

.include "../../mk/bsd.prefs.mk"

DSPAM_HOME?=		${VARBASE}/dspam
DSPAM_SIGNATURE_LIFE?=	14

DSPAM_BINMODE?=		4511
DSPAM_USER?=		dspam
DSPAM_GROUP?=		dspam

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-chi-square
CONFIGURE_ARGS+=	--enable-robinson-pvalues
CONFIGURE_ARGS+=	--with-signature-life=${DSPAM_SIGNATURE_LIFE}
CONFIGURE_ARGS+=	--with-dspam-home=${DSPAM_HOME}			\
			--with-dspam-home-owner=${DSPAM_USER}		\
			--with-dspam-home-group=${DSPAM_GROUP}		\
			--with-dspam-owner=${DSPAM_USER}		\
			--with-dspam-group=${DSPAM_GROUP}		\
			--with-dspam-mode=${DSPAM_BINMODE}

.include "options.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

DOCDIR=		${PREFIX}/share/doc/dspam
DATADIR=	${PREFIX}/share/dspam

USE_PKGINSTALL=		yes
PKG_GROUPS=		${DSPAM_GROUP}
PKG_USERS=		${DSPAM_USER}:${DSPAM_GROUP}
SPECIAL_PERMS=		${PREFIX}/bin/dspam ${DSPAM_USER} ${DSPAM_GROUP} \
			${DSPAM_BINMODE}
OWN_DIRS_PERMS=		${DSPAM_HOME} ${DSPAM_USER} ${DSPAM_GROUP} 0770

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASE.NOTES ${DOCDIR}
	${INSTALL_DATA_DIR} ${DATADIR}
.for d in txt cgi
	${INSTALL_DATA_DIR} ${DATADIR}/${d}
	cd ${WRKSRC}/${d} && ${PAX} -rwppm '-s|.*/Makefile.*$$||'	\
		. ${DATADIR}/${d}
.endfor
.undef d
.if !empty(DSPAM_STORAGE_DRIVER:Mmysql)
	${INSTALL_DATA_DIR} ${DATADIR}/mysql
	cd ${WRKSRC}/tools.mysql_drv && ${PAX} -rwppm '-s|.*/Makefile.*$$||' \
		. ${DATADIR}/mysql
.endif
.if !empty(DSPAM_STORAGE_DRIVER:Mpgsql)
	${INSTALL_DATA_DIR} ${DATADIR}/pgsql
	cd ${WRKSRC}/tools.pgsql_drv && ${PAX} -rwppm '-s|.*/Makefile.*$$||' \
		. ${DATADIR}/pgsql
.endif

.include "../../mk/bsd.pkg.mk"
