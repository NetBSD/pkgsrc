# $NetBSD: Makefile,v 1.18 2012/10/03 13:01:43 asau Exp $
#

DISTNAME=	dpbox-60000
PKGNAME=	dpbox-6.00.00
PKGREVISION=	3
CATEGORIES=	ham
MASTER_SITES=	http://home.snafu.de/wahlm/dl8hbs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.snafu.de/wahlm/dl8hbs/dpbox.html
COMMENT=	Multi-Protocol Amateur Packet Radio BBS

WRKSRC=		${WRKDIR}/dpbox-6.00.00/source
USE_TOOLS+=	gmake
MAKE_FILE=	Makefile.netbsd

MAKE_ENV+=	prefix=${PREFIX:Q}
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFDIR.dpbox=${PREFIX}/share/dpbox/conf

DPBOX_CONF_DIR=	${PKG_SYSCONFDIR}
DPBOX_SPOOL_DIR=/var/spool/dpbox
FILES_SUBST+=	DPBOX_CONF_DIR=${DPBOX_CONF_DIR:Q} \
		DPBOX_SPOOL_DIR=${DPBOX_SPOOL_DIR:Q}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}/conf

REQD_DIRS=	${PKG_SYSCONFDIR} \
		${PKG_SYSCONFDIR}/sf \
		${PKG_SYSCONFDIR}/system \
		${DPBOX_SPOOL_DIR}/crawler \
		${DPBOX_SPOOL_DIR}/fileserv \
		${DPBOX_SPOOL_DIR}/fileserv/incoming \
		${DPBOX_SPOOL_DIR}/fileserv/temp7pl \
		${DPBOX_SPOOL_DIR}/fileserv/newbin \
		${DPBOX_SPOOL_DIR}/indexes \
		${DPBOX_SPOOL_DIR}/infofiles \
		${DPBOX_SPOOL_DIR}/import \
		${DPBOX_SPOOL_DIR}/newmail \
		${DPBOX_SPOOL_DIR}/privserv \
		${DPBOX_SPOOL_DIR}/privserv/temp7pl \
		${DPBOX_SPOOL_DIR}/proto \
		${DPBOX_SPOOL_DIR}/save \
		${DPBOX_SPOOL_DIR}/server \
		${DPBOX_SPOOL_DIR}/stat \
		${DPBOX_SPOOL_DIR}/stat/extusers

CONF_FILES=	${EGDIR}/dpbox.ini ${PKG_SYSCONFDIR}/dpbox.ini \
		${EGDIR}/crawler/stopwords ${DPBOX_SPOOL_DIR}/crawler/stopwords \
		${EGDIR}/sf/db0xyz.sf ${PKG_SYSCONFDIR}/sf/db0xyz.sf \
		${EGDIR}/system/badwords.box ${PKG_SYSCONFDIR}/system/badwords.box \
		${EGDIR}/system/bcast.box ${PKG_SYSCONFDIR}/system/bcast.box \
		${EGDIR}/system/beacon.box ${PKG_SYSCONFDIR}/system/beacon.box \
		${EGDIR}/system/commands.box ${PKG_SYSCONFDIR}/system/commands.box \
		${EGDIR}/system/config.box ${PKG_SYSCONFDIR}/system/config.box \
		${EGDIR}/system/convlt.box ${PKG_SYSCONFDIR}/system/convlt.box \
		${EGDIR}/system/convtit.box ${PKG_SYSCONFDIR}/system/convtit.box \
		${EGDIR}/system/cookies.doc ${PKG_SYSCONFDIR}/system/cookies.doc \
		${EGDIR}/system/digimap.stn ${PKG_SYSCONFDIR}/system/digimap.stn \
		${EGDIR}/system/prefix.inf ${PKG_SYSCONFDIR}/system/prefix.inf \
		${EGDIR}/system/prefix.sub ${PKG_SYSCONFDIR}/system/prefix.sub \
		${EGDIR}/system/prvcalls.box ${PKG_SYSCONFDIR}/system/prvcalls.box \
		${EGDIR}/system/reject.box ${PKG_SYSCONFDIR}/system/reject.box \
		${EGDIR}/system/rubriken.box ${PKG_SYSCONFDIR}/system/rubriken.box \
		${EGDIR}/system/tcpip.box ${PKG_SYSCONFDIR}/system/tcpip.box \
		${EGDIR}/system/transfer.box ${PKG_SYSCONFDIR}/system/transfer.box \
		${EGDIR}/system/unproto.box ${PKG_SYSCONFDIR}/system/unproto.box \
		${EGDIR}/system/whotalks.lan ${PKG_SYSCONFDIR}/system/whotalks.box

post-build:
	${SED} -e 's#@prefix@#${PREFIX}#g' \
		< ${FILESDIR}/dpbox.ini > ${WRKDIR}/dpbox-6.00.00/dpbox.ini

.include "../../mk/bsd.pkg.mk"
