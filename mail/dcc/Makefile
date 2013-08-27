# $NetBSD: Makefile,v 1.6 2013/08/27 16:40:11 shattered Exp $
#
#	Request by the author:
#
#	On Thu, Jan 29, 2009 at 06:27:03PM +0000,
#	Vernon Schryver wrote:
#	>
#	> There should be no patches in whatever
#	> you distribute. Updatedcc must work.
#
DISTNAME=		dcc-1.3.123
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://www.rhyolite.com/dcc/source/old/
EXTRACT_SUFX=		.tar.Z

OWNER=			petar@smokva.net
HOMEPAGE=		http://www.rhyolite.com/dcc/
COMMENT=		Anti-spam content filter
LICENSE=		dcc-free-license

.include "../../mk/bsd.prefs.mk"

DCC_USER?=		dcc
DCC_GROUP?=		dcc
DCC_HOME?=		${VARBASE}/dcc
DCC_RUN?=		${VARBASE}/run/dcc

# expanded in INSTALL
FILES_SUBST+=		DCC_USER=${DCC_USER} \
			DCC_GROUP=${DCC_GROUP} \
			DCC_HOME=${DCC_HOME} \
			DCC_EGDIR=${DCC_EGDIR}

# expanded in files/dcc{d,ifd,m}
FILES_SUBST+=		DCC_RUN=${DCC_RUN}

SUBST_CLASSES+=		dae
SUBST_STAGE.dae=	post-patch
SUBST_FILES.dae=	homedir/dcc_conf.in
SUBST_SED.dae=		-e 's/^\(DCCD_ENABLE=\)off$$/\1on/'
SUBST_SED.dae+=		-e 's/^\(DCCM_ENABLE=\)off$$/\1on/'
SUBST_SED.dae+=		-e 's/^\(DCCIFD_ENABLE=\)off$$/\1on/'
SUBST_MESSAGE.dae=	Enabling all daemons in dcc_conf

HAS_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no

CONFIGURE_ENV+=		PERL=${PERL5:Q} \
			DCC_XARGS=${XARGS:Q}

CONFIGURE_ARGS+=	--homedir=${DCC_HOME} \
			--bindir=${PREFIX}/bin \
			--libexecdir=${PREFIX}/libexec \
			--mandir=${PREFIX}/${PKGMANDIR} \
			--with-make-cmd=${MAKE_PROGRAM:Q} \
			--with-rundir=${DCC_RUN} \
			--with-uid=${DCC_USER}

.include "options.mk"

BUILD_DEFS+=		VARBASE

INSTALLATION_DIRS+=	bin libexec ${PKGMANDIR}/man8 \
			share/examples/dcc/cgi-bin

PKG_GROUPS=		${DCC_GROUP}
PKG_USERS=		${DCC_USER}:${DCC_GROUP}

OWN_DIRS_PERMS+=	${DCC_HOME} ${DCC_USER} ${DCC_GROUP} 0755 \
			${DCC_HOME}/log ${DCC_USER} ${DCC_GROUP} 0710

DCC_EGDIR=		${PREFIX}/share/examples/dcc
DCC_PERMS_CONFIG=	${ROOT_USER} ${ROOT_GROUP} 0644
CONF_FILES_PERMS+=	${DCC_EGDIR}/dcc_conf ${DCC_HOME}/dcc_conf ${DCC_PERMS_CONFIG} \
			${DCC_EGDIR}/flod ${DCC_HOME}/flod ${DCC_PERMS_CONFIG} \
			${DCC_EGDIR}/grey_flod ${DCC_HOME}/grey_flod ${DCC_PERMS_CONFIG} \
			${DCC_EGDIR}/grey_whitelist ${DCC_HOME}/grey_whitelist ${DCC_PERMS_CONFIG} \
			${DCC_EGDIR}/whiteclnt ${DCC_HOME}/whiteclnt ${DCC_PERMS_CONFIG} \
			${DCC_EGDIR}/whitecommon ${DCC_HOME}/whitecommon ${DCC_PERMS_CONFIG} \
			${DCC_EGDIR}/whitelist ${DCC_HOME}/whitelist ${DCC_PERMS_CONFIG}
RCD_SCRIPTS+=		dccd dccifd

DCC_PERMS_SETUID=	${DCC_USER} ${ROOT_GROUP} 4555
SPECIAL_PERMS+=		bin/cdcc ${DCC_PERMS_SETUID} \
			bin/dccproc ${DCC_PERMS_SETUID} \
			libexec/dccsight ${DCC_PERMS_SETUID}

post-build:
	${SED} -e "s!@DCC_HOME@!${DCC_HOME}!g" ${FILESDIR}/dcc-spamassassin.pre \
		>${WRKDIR}/dcc-spamassassin.pre

# options.mk/dccm adds a dependency on do-install.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdcc/cdcc ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/ck2ip/ck2ip ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_PROGRAM} ${WRKSRC}/dbclean/dbclean ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_PROGRAM} ${WRKSRC}/dblist/dblist ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_PROGRAM} ${WRKSRC}/dccd/dccd ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_PROGRAM} ${WRKSRC}/dccifd/dccifd ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_PROGRAM} ${WRKSRC}/dccproc/dccproc ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/dccsight/dccsight ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_PROGRAM} ${WRKSRC}/dns-helper/dns-helper ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_PROGRAM} ${WRKSRC}/misc/wlist ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/cgi-bin/chgpasswd ${DESTDIR}${DCC_EGDIR}/cgi-bin/
	${INSTALL_SCRIPT} ${WRKSRC}/cgi-bin/common ${DESTDIR}${DCC_EGDIR}/cgi-bin/
	${INSTALL_SCRIPT} ${WRKSRC}/cgi-bin/edit-whiteclnt ${DESTDIR}${DCC_EGDIR}/cgi-bin/
	${INSTALL_SCRIPT} ${WRKSRC}/cgi-bin/http2https ${DESTDIR}${DCC_EGDIR}/cgi-bin/
	${INSTALL_SCRIPT} ${WRKSRC}/cgi-bin/list-log ${DESTDIR}${DCC_EGDIR}/cgi-bin/
	${INSTALL_SCRIPT} ${WRKSRC}/cgi-bin/list-msg ${DESTDIR}${DCC_EGDIR}/cgi-bin/
	${INSTALL_SCRIPT} ${WRKSRC}/cgi-bin/webuser-notify ${DESTDIR}${DCC_EGDIR}/cgi-bin/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/cron-dccd ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/dcc-nagios ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/dcc-stats-collect ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/dcc-stats-graph ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/dcc-stats-init ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/fetch-testmsg-whitelist ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/fetchblack ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/fetchids ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/hackmc ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/list-clients ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/logger ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/newwebuser ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/rcDCC ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/start-dccd ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/start-dccifd ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/start-dccm ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/start-grey ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/stats-get ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/stop-dccd ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/uninstalldcc ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/misc/updatedcc ${DESTDIR}${PREFIX}/libexec/
	${INSTALL_MAN} ${WRKSRC}/cdcc.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_MAN} ${WRKSRC}/dbclean.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_MAN} ${WRKSRC}/dblist.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_MAN} ${WRKSRC}/dcc.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_MAN} ${WRKSRC}/dccd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_MAN} ${WRKSRC}/dccifd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_MAN} ${WRKSRC}/dccm.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_MAN} ${WRKSRC}/dccproc.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_MAN} ${WRKSRC}/dccsight.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/README ${DESTDIR}${DCC_EGDIR}/cgi-bin/
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/footer ${DESTDIR}${DCC_EGDIR}/cgi-bin/
	${INSTALL_DATA} ${WRKSRC}/cgi-bin/header ${DESTDIR}${DCC_EGDIR}/cgi-bin/
	${INSTALL_DATA} ${WRKSRC}/homedir/dcc_conf ${DESTDIR}${DCC_EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/homedir/flod ${DESTDIR}${DCC_EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/homedir/grey_flod ${DESTDIR}${DCC_EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/homedir/grey_whitelist ${DESTDIR}${DCC_EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/homedir/ids ${DESTDIR}${DCC_EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/homedir/map.txt ${DESTDIR}${DCC_EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/homedir/whiteclnt ${DESTDIR}${DCC_EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/homedir/whitecommon ${DESTDIR}${DCC_EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/homedir/whitelist ${DESTDIR}${DCC_EGDIR}/
	${INSTALL_DATA} ${WRKDIR}/dcc-spamassassin.pre ${DESTDIR}${DCC_EGDIR}/

.include "../../mk/bsd.pkg.mk"
