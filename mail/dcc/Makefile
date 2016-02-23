# $NetBSD: Makefile,v 1.11 2016/02/23 15:24:50 gdt Exp $

DISTNAME=		dcc-1.3.158
PKGREVISION=		1
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

# dcc already implements $DESTDIR as $installroot but also prepends
# $installroot to $BINDIR, which bsd.prog.mk subsequently extends to
# $DESTDIR/$BINDIR, effectively doubling the $DESTDIR prefix.  The
# following bit of make dances around the issue and avoids adding
# $DESTDIR when evaluated within a bsd.prog.mk target.
DCC_DESTDIR=		$${"$${@:Mproginstall-*}"=="":?$${DESTDIR}:}

# expanded in files/dcc*.sh
FILES_SUBST+=		DCC_HOME=${DCC_HOME}
FILES_SUBST+=		DCC_EGDIR=${DCC_EGDIR}
FILES_SUBST+=		DCC_RC=${PREFIX}/libexec/rcDCC
FILES_SUBST+=		DCC_FIXMAP=${PREFIX}/libexec/fix-map

# enabling/disabling daemons is done in rc.conf
SUBST_CLASSES+=		dae
SUBST_STAGE.dae=	post-patch
SUBST_FILES.dae=	homedir/dcc_conf.in
SUBST_SED.dae=		-e 's/^\(DCCD_ENABLE=\).*$$/\1on/'
SUBST_SED.dae+=		-e 's/^\(GREY_ENABLE=\).*$$/\1on/'
SUBST_SED.dae+=		-e 's/^\(DCCM_ENABLE=\).*$$/\1on/'
SUBST_SED.dae+=		-e 's/^\(DCCIFD_ENABLE=\).*$$/\1on/'
SUBST_MESSAGE.dae=	Enabling all daemons in dcc_conf

HAS_CONFIGURE=		yes

USE_TOOLS+=		xargs:run
USE_TOOLS+=		ftp:run

CONFIGURE_ENV+=		DCC_XARGS=${TOOLS_PATH.xargs:Q}
# See --with-fetch-cmd for ftp..

# dcc provides certain auxiliary scripts used for its web-UI and stats
# management.  Since these scripts are non-essential, the bulky tools
# they rely on are not declared as dependencies.
CONFIGURE_ENV+=		PERL=${DCC_HOME}/bin/perl
CONFIGURE_ENV+=		NOTIFYMAILER=${DCC_HOME}/bin/sendmail
CONFIGURE_ENV+=		HTPASSWD=${DCC_HOME}/bin/htpasswd
CONFIGURE_ENV+=		RRDTOOL=${DCC_HOME}/bin/rrdtool

CONFIGURE_ARGS+=	--homedir=${DCC_HOME}
CONFIGURE_ARGS+=	--bindir=${PREFIX}/bin
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--with-cgi-bin=${DCC_EGDIR}/cgi-bin
CONFIGURE_ARGS+=	--with-rundir=${DCC_RUN}
CONFIGURE_ARGS+=	--with-uid=${DCC_USER}
CONFIGURE_ARGS+=	--with-make-cmd=${MAKE_PROGRAM:Q}
CONFIGURE_ARGS+=	--with-fetch-cmd=${TOOLS_PATH.ftp:Q}
CONFIGURE_ARGS+=	--with-installroot=\$$\(DCC_DESTDIR\)
CONFIGURE_ARGS+=	--disable-sys-inst
CONFIGURE_ARGS+=	--disable-dccm

USE_BSD_MAKEFILE=	yes
MAKE_JOBS_SAFE=		no

# PKGSRC_DCC_EGDIR is for homedir/Makefile
MAKE_ENV+=		PKGSRC_DCC_EGDIR=${DCC_EGDIR}
MAKE_ENV+=		DCC_DESTDIR=${DCC_DESTDIR:Q}
MAKE_ENV+=		NO_SUID=yes

BUILD_DEFS+=		VARBASE

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	${PKGMANDIR}/man8
INSTALLATION_DIRS+=	${DCC_EGDIR_REL}
INSTALLATION_DIRS+=	${DCC_EGDIR_REL}/cgi-bin

PKG_GROUPS=		${DCC_GROUP}
PKG_USERS=		${DCC_USER}:${DCC_GROUP}

OWN_DIRS_PERMS+=	${DCC_HOME} ${DCC_USER} ${DCC_GROUP} 0755
OWN_DIRS_PERMS+=	${DCC_HOME}/log ${DCC_USER} ${DCC_GROUP} 0710

DCC_EGDIR_REL=		share/examples/dcc
DCC_EGDIR=		${PREFIX}/${DCC_EGDIR_REL}
DCC_PERMS_CONFIG=	${DCC_USER} ${DCC_GROUP} 0600
CONF_FILES_PERMS+=	${DCC_EGDIR}/dcc_conf ${DCC_HOME}/dcc_conf ${DCC_PERMS_CONFIG}
CONF_FILES_PERMS+=	${DCC_EGDIR}/flod ${DCC_HOME}/flod ${DCC_PERMS_CONFIG}
CONF_FILES_PERMS+=	${DCC_EGDIR}/grey_flod ${DCC_HOME}/grey_flod ${DCC_PERMS_CONFIG}
CONF_FILES_PERMS+=	${DCC_EGDIR}/grey_whitelist ${DCC_HOME}/grey_whitelist ${DCC_PERMS_CONFIG}
CONF_FILES_PERMS+=	${DCC_EGDIR}/whiteclnt ${DCC_HOME}/whiteclnt ${DCC_PERMS_CONFIG}
CONF_FILES_PERMS+=	${DCC_EGDIR}/whitecommon ${DCC_HOME}/whitecommon ${DCC_PERMS_CONFIG}
CONF_FILES_PERMS+=	${DCC_EGDIR}/whitelist ${DCC_HOME}/whitelist ${DCC_PERMS_CONFIG}
RCD_SCRIPTS+=		dccd dccifd

DCC_PERMS_SETUID=	${DCC_USER} ${REAL_ROOT_GROUP} 4555
SPECIAL_PERMS+=		bin/cdcc ${DCC_PERMS_SETUID}
SPECIAL_PERMS+=		bin/dccproc ${DCC_PERMS_SETUID}
SPECIAL_PERMS+=		libexec/dccsight ${DCC_PERMS_SETUID}

.include "../../mk/bsd.pkg.mk"
